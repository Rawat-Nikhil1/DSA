class Solution {
public:
    void bfs(vector<vector<int>>& adjLs, int node, vector<bool>& vis) {
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < adjLs[curr].size(); i++) {
                int neigh = adjLs[curr][i];

                if (vis[neigh] == false) {
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjLs(V);
        vector<bool> vis(V, false);

        // to change adjacency matrix to list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (vis[i] == false) {
                count++;
                bfs(adjLs, i, vis);
            }
        }
        return count;
    }
};