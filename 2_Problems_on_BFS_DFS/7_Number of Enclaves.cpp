class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if(grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                    else
                        vis[i][j] = 0;
                }
            }
        }
        while(!q.empty()) {
            int row = q.front().first, col = q.front().second;  q.pop();
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j])
                    ans++;
            }
        }
        return ans;
    }
};
