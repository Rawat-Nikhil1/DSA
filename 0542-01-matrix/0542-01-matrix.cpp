class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool isValid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    q.push({i, j});
                } else {
                    a[i][j] = -1;
                }
            }
        }

        while (!q.empty()) {

            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            for (int k = 0; k < 4; k++) {
                int row = r + x[k];
                int col = c + y[k];

                if (isValid(row, col, n, m) && a[row][col] == -1) {
                    a[row][col] = a[r][c] + 1;
                    q.push({row, col});
                }
            }
        }
        return a;
    }
};