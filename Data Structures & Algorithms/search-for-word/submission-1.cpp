class Solution {
public:
   bool dfs(int i, int j, int k, vector<vector<char>>& board, string word)
   {
      if(k==word.size()) return true;

      if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || word[k]!=board[i][j]
      || board[i][j]=='#') return false;
     char temp = board[i][j];
        board[i][j] = '#'; 
      if(dfs(i+1,j,k+1,board,word) || dfs(i-1,j,k+1,board,word) ||
          dfs(i,j+1,k+1,board,word) || dfs(i,j-1,k+1,board,word))
          return true;
 board[i][j] = temp; 
      return false;

   }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size(), m=board[0].size();

        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(board[i][j]==word[0] && dfs(i,j,0,board,word)) return true;
        }

        return false;
    }
};
