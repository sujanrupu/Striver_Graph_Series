class Solution {
public:
    void solve(vector<vector<int>>& image, vector<vector<int>>& ans, int row, int col, int color, int init_color, int dx[], int dy[]) {
        ans[row][col] = color;
        int n = image.size(), m = image[0].size();
        for(int i = 0; i < 4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] != color && image[nrow][ncol] == init_color)
                solve(image, ans, nrow, ncol, color, init_color, dx, dy);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int init_color = image[sr][sc];
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        solve(image, ans, sr, sc, color, init_color, dx, dy);
        return ans;
    }
};
