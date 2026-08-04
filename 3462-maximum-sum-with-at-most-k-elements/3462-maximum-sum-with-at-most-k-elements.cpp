class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {

        priority_queue<int> pq;

        int n = grid.size();

        for (int i = 0; i < n; i++) {

            sort(grid[i].begin(), grid[i].end(), greater<int>());

            for (int j = 0; j < limits[i] && j < grid[i].size(); j++) {
                pq.push(grid[i][j]);
            }
        }

        long long ans = 0;

        while (k-- && !pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};