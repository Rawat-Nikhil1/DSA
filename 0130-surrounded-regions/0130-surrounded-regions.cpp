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

    void solve(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (a[i][j] == 'O') {

                    vector<pair<int, int>> v;
                    bool boundary = false;

                    q.push({i, j});
                    a[i][j] = '#';

                    while (!q.empty()) {

                        pair<int, int> t = q.front();
                        q.pop();

                        int r = t.first;
                        int c = t.second;

                        v.push_back({r, c});

                        // Check boundary
                        if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
                            boundary = true;
                        }

                        // Check 4 directions
                        for (int k = 0; k < 4; k++) {

                            int row = r + x[k];
                            int col = c + y[k];

                            if (isValid(row, col, n, m) && a[row][col] == 'O') {

                                q.push({row, col});
                                a[row][col] = '#';
                            }
                        }
                    }

                    // Region touches boundary
                    if (boundary) {
                        for (auto p : v) {
                            a[p.first][p.second] = 'O';
                        }
                    }

                    // Region doesn't touch boundary
                    else {
                        for (auto p : v) {
                            a[p.first][p.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};