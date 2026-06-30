class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                !vis[ni][nj] && grid[ni][nj] == 1) {
                dfs(ni, nj, vis, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0])
                dfs(i, 0, vis, grid);

            if (grid[i][m - 1] == 1 && !vis[i][m - 1])
                dfs(i, m - 1, vis, grid);
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1 && !vis[0][j])
                dfs(0, j, vis, grid);

            if (grid[n - 1][j] == 1 && !vis[n - 1][j])
                dfs(n - 1, j, vis, grid);
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j])
                    cnt++;
            }
        }

        return cnt;
    }
};