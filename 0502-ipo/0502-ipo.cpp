class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<pair<int, int>> proj;
        int n = capital.size();

        for (int i = 0; i < n; i++) {
            proj.push_back({capital[i], profits[i]});
        }

        sort(proj.begin(), proj.end());

        priority_queue<int> pq;

        int idx = 0;
        for (int i = 0; i < k; i++) {
            while (idx < n) {
                if (proj[idx].first > w) {
                    break;
                } else {
                    pq.push(proj[idx].second);
                    idx++;
                }
            }
            if (pq.empty()) {
                return w;
            }
            w = w + pq.top();
            pq.pop();
        }
        return w;
    }
};