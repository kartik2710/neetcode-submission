
class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& board, vector<vector<int>>& vis)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == 1 || board[i][j] == 'X')
            return;

        vis[i][j] = 1;

        dfs(i+1, j, n, m, board, vis);
        dfs(i-1, j, n, m, board, vis);
        dfs(i, j+1, n, m, board, vis);
        dfs(i, j-1, n, m, board, vis);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Left and Right boundaries
        for(int i = 0; i < n; i++) {
            dfs(i, 0, n, m, board, vis);
            dfs(i, m-1, n, m, board, vis);
        }

        // Top and Bottom boundaries
        for(int j = 0; j < m; j++) {
            dfs(0, j, n, m, board, vis);
            dfs(n-1, j, n, m, board, vis);
        }

        // Flip unvisited 'O' to 'X'
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && vis[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};

