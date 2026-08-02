class Solution {
public:
    int dist(int num, int x) { return abs(num - x); }

    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int n = arr.size();

        for (int i = 0; i < k; i++) {
            pq.push({dist(arr[i], x), arr[i]});
        }

        for (int i = k; i < n; i++) {
            if (dist(arr[i], x) < pq.top().first) {
                pq.pop();
                pq.push({dist(arr[i], x), arr[i]});
            }
            else if (dist(arr[i], x) == pq.top().first) {
                if (arr[i] < pq.top().second) {
                    pq.pop();
                    pq.push({dist(arr[i], x), arr[i]});
                }
            }
        }

        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};