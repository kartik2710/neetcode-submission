class Solution {
public:
    int sol(int i, vector<int> &coins, int amount,   vector<vector<int>> &dp)
    {
        if(amount==0) return 0;
      
        if(i==0)
        {
          //  
            if(amount%coins[0]==0) return amount/coins[0];
            return INT_MAX;

        }
        if(dp[i][amount]!=-1) return dp[i][amount];

        int include=INT_MAX, exclude=INT_MAX;

        if(coins[i]<=amount)
        {
            include=sol(i,coins,amount-coins[i],dp);
            if(include!=INT_MAX) include++;
        }

        exclude=sol(i-1,coins,amount,dp);

        return dp[i][amount]=min(include, exclude);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans= sol(coins.size()-1,coins, amount,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
