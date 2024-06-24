class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>>q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
                else
                    vis[i][j] = 0;
            }
        }
        vector<vector<int>>dist(n, vector<int>(m, 0));
        while(!q.empty()) {
            int row = q.front().first.first, col = q.front().first.second, steps = q.front().second;
            q.pop();
            dist[row][col] = steps;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i ++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, steps+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return dist;
    }
};
