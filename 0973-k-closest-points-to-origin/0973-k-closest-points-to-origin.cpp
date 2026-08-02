class Solution {
public:
    int distanceFromOrigin(vector<int>& point) {
        int x = point[0];
        int y = point[1];

        return x * x + y * y;
    }

    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int n = points.size();

        for (int i = 0; i < k; i++) {
            pq.push({distanceFromOrigin(points[i]), i});
        }

        for (int i = k; i < n; i++) {
            int dist = distanceFromOrigin(points[i]);

            if (dist < pq.top().first) {
                pq.pop();
                pq.push({dist, i});
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            int idx = pq.top().second;
            ans.push_back(points[idx]);
            pq.pop();
        }

        return ans;
    }
};