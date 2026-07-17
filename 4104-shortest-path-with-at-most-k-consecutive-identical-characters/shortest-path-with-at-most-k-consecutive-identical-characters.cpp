class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto state = pq.top();
            pq.pop();

            long long d = state[0];
            int u = state[1];
            int cnt = state[2];

            if (d != dist[u][cnt]) continue;

            for (auto &[v, w] : adj[u]) {
                int newCnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if (newCnt > k) continue;

                if (dist[v][newCnt] > d + w) {
                    dist[v][newCnt] = d + w;
                    pq.push({dist[v][newCnt], (long long)v, (long long)newCnt});
                }
            }
        }

        long long ans = INF;

        for (int i = 1; i <= k; i++) {
            ans = min(ans, dist[n - 1][i]);
        }

        return (ans == INF) ? -1 : static_cast<int>(ans);
    }
};