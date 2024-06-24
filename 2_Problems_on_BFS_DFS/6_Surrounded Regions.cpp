class Solution {
public:
    void solve(vector<vector<char>>& board, vector<vector<int>>& vis, int row, int col, int dx[], int dy[]) {
        int n = board.size(), m = board[0].size();
        vis[row][col] = 1;
        for(int i = 0; i < 4; i ++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
                solve(board, vis, nrow, ncol, dx, dy);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        // check for topmost and bottommost row
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O' && !vis[0][j])
                solve(board, vis, 0, j, dx, dy);
            if(board[n-1][j] == 'O' && !vis[n-1][j])
                solve(board, vis, n-1, j, dx, dy);
        }

        // check for leftmost and rightmost column
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O' && !vis[i][0])
                solve(board, vis, i, 0, dx, dy);
            if(board[i][m-1] == 'O' && !vis[i][m-1])
                solve(board, vis, i, m-1, dx, dy);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }

    }
};
