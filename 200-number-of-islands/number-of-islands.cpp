class Solution {
public:
    bool valid(int i, int j, vector<vector<char>>& grid,
               vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        return (i >= 0 && i < n &&
                j >= 0 && j < m &&
                grid[i][j] == '1' &&
                !vis[i][j]);
    }

    void dfs(int i, int j,
             vector<vector<int>>& vis,
             vector<vector<char>>& grid) {

        vis[i][j] = 1;

        if(valid(i+1,j,grid,vis)) dfs(i+1,j,vis,grid);
        if(valid(i-1,j,grid,vis)) dfs(i-1,j,vis,grid);
        if(valid(i,j-1,grid,vis)) dfs(i,j-1,vis,grid);
        if(valid(i,j+1,grid,vis)) dfs(i,j+1,vis,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, vis, grid);
                    count++;
                }
            }
        }

        return count;
    }
};