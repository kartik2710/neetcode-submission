class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m,0));
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        if(grid[i][j]==2)
        q.push({i,j});

      vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};

      int val=1;
        while(!q.empty())
        {
            int size=q.size();

            while(size--)
            {
               int i=q.front().first;
               int j=q.front().second;
               q.pop();

               for(auto x: dir)
               {
                   int newx=x[0]+i, newy=x[1]+j;

                   if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==1 && dp[newx][newy]==0 )
                   {
                    dp[newx][newy]=val;
                    q.push({newx,newy});
                    
                   }
               }


            }
            val++;
        }
        
        int ans=0;

        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        if(grid[i][j]==1)
        {
            if(dp[i][j]==0) return -1;
            ans=max(ans,dp[i][j]);

        }

        return ans;

    }
};
