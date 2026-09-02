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
        int n=s.size(),c=0;
      vector<vector<int>> dp(n, vector<int>(n,0));

      for(int i=0; i<n; i++) dp[i][i]=1,c++;

      for(int i=0; i<n-1; i++)
      if(s[i]==s[i+1])
      {
        dp[i][i+1]=1;
        c++;
      }


      for(int k=2; k<=n; k++)
      for(int i=0; i<n-k+1; i++)
        {
            int j=i+k-1;

            if(dp[i+1][j-1] && s[i]==s[j])
            {
                dp[i][j]=1;
                c++;
            }
        }
      

      return c;


    }
};
