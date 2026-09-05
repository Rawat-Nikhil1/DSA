class Solution {
public:
    void bfs(vector<vector<int>>& isConnected, int node, vector<bool>& vis) {
        queue<int> q;
        q.push(node);
        vis[node] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < isConnected[curr].size(); i++) {

                if (isConnected[curr][i] == 1 && !vis[i]) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int vertices = isConnected.size();
        vector<bool> vis(vertices, false);
        int count = 0;

        for (int i = 0; i < vertices; i++) {
            if (vis[i] == false) {
                count++;
                bfs(isConnected, i, vis);
            }
        }
        return count;
    }
};