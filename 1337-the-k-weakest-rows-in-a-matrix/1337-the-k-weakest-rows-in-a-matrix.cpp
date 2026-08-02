class Solution {
public:
    int countSoldiers(vector<int>& row) {
        int cnt = 0;
        for( int i=0 ; i<row.size();i++){
            if(row[i]==1){
                cnt++;
            }
        }
        return cnt;
    }

    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {

            if (a.first != b.first){
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> pq;
        int m = mat.size();

        for (int i = 0; i < k; i++) {
            int soldiers = countSoldiers(mat[i]);
            pq.push({soldiers, i});
        }

        for (int i = k; i < m; i++) {

            int soldiers = countSoldiers(mat[i]);

            if (soldiers < pq.top().first) {
                pq.pop();
                pq.push({soldiers, i});
            }
            else if (soldiers == pq.top().first) {

                if (i < pq.top().second) {
                    pq.pop();
                    pq.push({soldiers, i});
                }
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};