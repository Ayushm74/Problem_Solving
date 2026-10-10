
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int originalColor = image[sr][sc];

        if (originalColor == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        image[sr][sc] = color;

      int delRow[] = {-1,0,1,0};
      int delCol[] = {0,-1,0,1};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = x + delRow[i];
                int nc = y + delCol[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    image[nr][nc] == originalColor) {

                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};
