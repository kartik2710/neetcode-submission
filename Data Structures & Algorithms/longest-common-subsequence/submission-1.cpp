class Solution {
public:
    int sol(int i, int j, string x, string y,  vector<vector<int>> &dp)
    {
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(x[i]==y[j])
         return dp[i][j]=1+sol(i-1,j-1,x,y,dp);
         return dp[i][j]=max(sol(i-1,j,x,y,dp),sol(i,j-1,x,y,dp));
    }
    int longestCommonSubsequence(string x, string y) {
        int n=x.size(), m=y.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return sol(n-1,m-1,x,y,dp);
    }
};
