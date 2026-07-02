class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int &cnt) {
        vis[node] = 1;
        cnt++;

        for (int nei : adj[node]) {
            if (!vis[nei])
                dfs(nei, adj, vis, cnt);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r = bombs[i][2];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];

                long long dx = x1 - x2;
                long long dy = y1 - y2;

                long long dist = dx * dx + dy * dy;

                if (dist <= r * r) {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            int cnt = 0;

            dfs(i, adj, vis, cnt);

            ans = max(ans, cnt);
        }

        return ans;
    }
};