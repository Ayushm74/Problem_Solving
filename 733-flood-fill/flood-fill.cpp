
class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j,
             int originalColor, int color) {
        int m = image.size();
        int n = image[0].size();

        // Check boundaries and original color
        if (i < 0 || j < 0 || i >= m || j >= n ||
            image[i][j] != originalColor) {
            return;
        }

        // Change the pixel color
        image[i][j] = color;

        // Explore all 4 directions
        dfs(image, i + 1, j, originalColor, color); // Down
        dfs(image, i - 1, j, originalColor, color); // Up
        dfs(image, i, j + 1, originalColor, color); // Right
        dfs(image, i, j - 1, originalColor, color); // Left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {
        int originalColor = image[sr][sc];

        // Avoid unnecessary DFS
        if (originalColor == color) {
            return image;
        }

        dfs(image, sr, sc, originalColor, color);

        return image;
    }
};
