class Solution {
public:
  bool check(string s)
  {
    int count=0;
    for(auto x: s)
    {
        if(x=='(') count++;
        else count--;
        if(count<0) return false;
    }

    return count==0;
  }
   bool sol(int i, string s, vector<vector<int>> &dp, int c)
    {
        if(c<0) return false;
        if(i==s.size()) return c==0;
        if(dp[i][c]!=-1) return dp[i][c];
        if(s[i]=='(')
        return dp[i][c]= sol(i+1,s,dp,c+1);
        else if(s[i]==')')
          return dp[i][c]=sol(i+1,s,dp,c-1);


         return dp[i][c]=sol(i+1,s,dp,c+1) || sol(i+1,s,dp,c-1) || sol(i+1,s,dp,c);



    }
    bool checkValidString(string s) {
      vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,-1));
      return sol(0,s,dp,0);

    }
};
