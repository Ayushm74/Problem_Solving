
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        queue<int> q;

        q.push(source);
        vis[source] = 1;

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (x == destination) {
                return true;
            }

            for (int neighbor : adj[x]) {
                if (vis[neighbor] == 0) {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};
