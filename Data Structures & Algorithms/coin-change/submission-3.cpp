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
        int n=coins.size();
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1,INT_MAX));

        for(int i=0; i<amount+1; i++)
         if(i%coins[0]==0) dp[0][i]=i/coins[0];


         for(int i=1; i<n+1; i++)
         for(int j=0; j<amount+1; j++)
         {
             int include=INT_MAX;
            if(coins[i-1]<=j)
            {          
                include= dp[i][j-coins[i-1]];
                if(include!=INT_MAX)
                include+=1;
            }
            int exclude=dp[i-1][j];

             dp[i][j]=min(include,exclude);
         }

         return dp[n][amount]==INT_MAX? -1: dp[n][amount];



     
    }
};
