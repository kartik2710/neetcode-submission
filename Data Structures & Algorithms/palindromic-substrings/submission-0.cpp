class Solution {
public:
     int sol(int i,int j, string &s, vector<vector<int>> &dp)
     {
          if(i==j) return 1;

          if(j==i+1 && s[i]==s[j]) return 1;

          if(dp[i][j]!=-1) return dp[i][j];

          return dp[i][j]=(s[i]==s[j] && sol(i+1,j-1,s,dp));
     }
    int countSubstrings(string s) {
        int n=s.size();
        int c=0;
      vector<vector<int>> dp(n, vector<int>(n,-1));

      for(int i=0; i<s.size(); i++)
      for(int j=i; j<s.size(); j++)
        if(sol(i,j,s,dp)) c++;
       

      return c;

    }
};
