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
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc,
                                  int color) {
        int n = a.size();
        int m = a[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        int oldcolor = a[sr][sc];
        if (oldcolor == color) {
            return a;
        }
        a[sr][sc] = color;

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            for (int k = 0; k < 4; k++) {
                int row = r + x[k];
                int col = c + y[k];

                if (isValid(row, col, n, m) && a[row][col] == oldcolor) {
                    q.push({row, col});
                    a[row][col] = color;
                }
            }
        }
        return a;
    }
};