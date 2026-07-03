class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis,
             vector<bool>& check, vector<int>& v1) {

        vis[i] = 1;

        if (adj[i].size() == 0) {
            check[i] = true;
            v1[i] = 1;
            return;
        }

        bool safe = true;

        for (auto it : adj[i]) {

            if (vis[it] == -1)
                dfs(it, adj, vis, check, v1);

            if (v1[it] != 1)
                safe = false;
        }

        if (safe) {
            check[i] = true;
            v1[i] = 1;
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<bool> check(n, false);
        vector<int> vis(n, -1);
        vector<int> v1(n, -1);

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1)
                dfs(i, graph, vis, check, v1);
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (check[i])
                ans.push_back(i);
        }

        return ans;
    }
};