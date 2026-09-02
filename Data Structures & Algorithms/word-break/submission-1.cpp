class Solution {
public:
    bool sol(int j, string s, unordered_map<string, int> &mp, vector<int> &dp)
    {
        if(j==s.size()) return true;
        if(dp[j]!=-1) return dp[j];
        for(auto x: mp)
        {
            string k=x.first;
            if(k==s.substr(j,k.size()))
            {
                if(sol(j+k.size(),s,mp,dp))  return dp[j]=true;
            }
        }
        return  dp[j]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_map<string, int> mp;
        for(auto x: wordDict)
        mp[x]++;
        vector<int> dp(s.size(),-1);
        return sol(0,s,mp,dp);


    }
};
