class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int V = n * n;

        vector<vector<int>> adj(V);

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        // Build adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int node = i * n + j;

                for (int k = 0; k < 4; k++) {

                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {

                        int nextNode = nr * n + nc;
                        adj[node].push_back(nextNode);
                    }
                }
            }
        }

        vector<int> dist(V, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[0] = grid[0][0];
        pq.push({grid[0][0], 0});

        while (!pq.empty()) {

            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node])
                continue;

            if (node == V - 1)
                return cost;

           

            for (int nei : adj[node]) {

                int nr = nei / n;
                int nc = nei % n;

                int newCost = max(cost, grid[nr][nc]);

                if (newCost < dist[nei]) {

                    dist[nei] = newCost;
                    pq.push({newCost, nei});
                }
            }
        }

        return dist[V - 1];
    }
};