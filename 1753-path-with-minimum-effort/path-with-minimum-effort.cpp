class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({0, {0, 0}});
        dis[0][0] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

           // if (row == m - 1 && col == n - 1) return diff;

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n) {
                    int newEffort = max(diff, abs(heights[nrow][ncol] - heights[row][col]));

                    if (newEffort < dis[nrow][ncol]) {
                        dis[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }

        return dis[m-1][n-1];
    }
};
