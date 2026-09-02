class Solution {
public:
    int sol(int i, int j,  vector<vector<int>> &dp)
    {
        if(i<0 || j<0) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        int down=sol(i-1,j,dp);
        int right=sol(i,j-1,dp);

        return dp[i][j]=down+right;


    }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m,0));
        dp[0][0]=1;

        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(i==0 && j==0) 
            continue;
              int down=0, right=0;
            if(i-1>=0)
             down=dp[i-1][j];
             if(j-1>=0)
             right=dp[i][j-1];
             dp[i][j]=down+right;

        }

        return dp[n-1][m-1];
        
    }
};
