class Solution {
public:
    int sol(int i, int j, string text1, string text2, vector<vector<int>> &dp)
    {
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i]==text2[j]) return  dp[i][j]=1+sol(i-1,j-1,text1,text2,dp);
        return  dp[i][j]=max(sol(i-1,j,text1,text2,dp), sol(i,j-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return sol(text1.size()-1, text2.size()-1, text1, text2,dp);
    }
};
