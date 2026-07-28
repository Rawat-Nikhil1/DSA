class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return false;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        unordered_map<int, int> f;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            f[nums[i]]++;
        }

        for (auto i : f) {

            pair<int, int> pairs = {i.second, i.first};

            if (pq.size() < k) {
                pq.push(pairs);
                continue;
            }
            if (pairs.first < pq.top().first) {
                continue;
            }
            pq.pop();
            pq.push(pairs);
        }
        vector<int> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};