class Solution {
public:
   bool check(int strt, int end, string s)
   {
      while(strt<end)
      {
        if(s[strt]!=s[end]) return false;
        strt++, end--;
      }

      return true;
   }
    string longestPalindrome(string s) {
    int n=s.size();

    vector<vector<int>> dp(n, vector<int>(n,0));
    int maxy=1,strt=0;

    for(int i=0; i<n; i++)
    dp[i][i]=1;

    for(int i=0; i<n-1; i++)
    if(s[i]==s[i+1])
    {
      dp[i][i+1]=1;
      strt=i, maxy=2;
    }

    for(int k=3; k<=n; k++)
    for(int i=0; i<n-k+1; i++)
    {
      int j=i+k-1;
      if(s[i]==s[j] && dp[i+1][j-1])
      {
        dp[i][j]=1;
        if(k>maxy)
        maxy=k,strt=i;
      }
    }

    return s.substr(strt,maxy);








    }
};
