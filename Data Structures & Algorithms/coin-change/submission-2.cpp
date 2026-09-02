class Solution {
public:
    int sol(int n, vector<int> coins, int amount, vector<vector<int>> &dp)
    {
        if(n==0)
        {
            if(amount%coins[0]==0) return amount/coins[0];
            return INT_MAX;
        }
        if(dp[n][amount]!=-1) return dp[n][amount];

        int include=INT_MAX;
        if(coins[n]<=amount)
        {
            include=sol(n,coins,amount-coins[n],dp);
            if(include!=INT_MAX)
             include+=1;
        }
        int exclude=sol(n-1,coins,amount,dp);

        return dp[n][amount]=min(include,exclude);

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
     int k=sol(coins.size()-1, coins, amount,dp);
     return k==INT_MAX? -1: k;
    }
};
