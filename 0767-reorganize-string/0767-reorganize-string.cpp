class Solution {
public:
    struct cmp {
        bool operator()(pair<int, char>& a, pair<int, char>& b) {
            if(a.first != b.first ){
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };
    string reorganizeString(string s) {
        int n = s.size();

        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        unordered_map<char, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
        }

        for (auto it : mpp) {
            int freq = it.second;
            char character = it.first;
            pq.push({freq, character});
        }

        string res = "";
        int seat = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if (seat == 0 || res[seat - 1] != p.second) {
                res.push_back(p.second);
                seat++;
                p.first--;
                if(p.first > 0){
                    pq.push(p);
                }
            }
            else{
                if(pq.empty()){
                    return "";
                }
                else{
                    pair<int , char>p2 = pq.top();
                    pq.pop();
                    res.push_back(p2.second);
                    seat++;
                    p2.first--;
                    pq.push(p);
                    
                    if(p2.first>0){
                        pq.push(p2);
                    }

                }
            }
        }
        return res;
    }
};