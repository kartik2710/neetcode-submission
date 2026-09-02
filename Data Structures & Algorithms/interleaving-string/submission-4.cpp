class Solution {
public:
    bool sol(int i, int  j, int k, string s1, string s2, string s3,  vector<vector<int>> &dp)
    {
          if(k==s3.size()) return true;
          if(i==s1.size() && j==s2.size()) return false;
          if(dp[i][j]!=-1) return dp[i][j];

          bool frst=false, sec=false;

          if(i<s1.size() && s1[i]==s3[k]) frst=sol(i+1,j,k+1,s1,s2,s3,dp);
          if(j<s2.size() && s2[j]==s3[k]) frst=sol(i,j+1,k+1,s1,s2,s3,dp);

          return dp[i][j]=frst || sec;

    }
    bool isInterleave(string s1, string s2, string s3) {
      int n=s1.size(), m=s2.size(), o=s3.size();
      if(n+m!=o) return false;
      vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
       dp[0][0]=1;

       for(int i=1; i<n+1; i++)
       for(int j=0; j<m+1; j++)
       {
         int k=i+j;
          bool frst=false, sec=false;
         if(s1[i-1]==s3[k-1]) frst=dp[i-1][j];
         if(s2[j-1]==s3[k-1]) sec=dp[i][j-1];

         dp[i][j]=frst || sec;



       }

       return dp[n][m];


    }
};
