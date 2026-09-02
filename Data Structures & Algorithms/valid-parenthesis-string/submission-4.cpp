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
     int miny=0, maxy=0;

     for(auto x: s)
     {
        if(x=='(') miny++, maxy++;
        else if(x==')') miny--,maxy--;
        else
        {
            miny--,maxy++;
        }

        if(miny<0) miny=0;
        if(maxy<0) return 0;
     }

     return miny==0;

    }
};
