class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid2,
             vector<vector<int>>& vis,
             vector<pair<int,int>>& island) {

        int n = grid2.size();
        int m = grid2[0].size();

        vis[i][j] = 1;
        island.push_back({i, j});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                !vis[ni][nj] && grid2[ni][nj] == 1) {
                dfs(ni, nj, grid2, vis, island);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int n = grid1.size();
        int m = grid1[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid2[i][j] == 1 && !vis[i][j]) {

                    vector<pair<int,int>> island;

                    dfs(i, j, grid2, vis, island);

                    bool ok = true;
                    for (auto &cell : island) {
                        if (grid1[cell.first][cell.second] == 0) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) ans++;
                }
            }
        }

        return ans;
    }
};