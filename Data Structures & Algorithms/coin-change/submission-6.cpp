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
        vector<vector<int>> dp(n+1, vector<int>(amount+1,INT_MAX));
         
         for(int i=0; i<amount+1; i++)
          if(i%coins[0]==0) dp[0][i]=i/coins[0];

          for(int i=1; i<n+1; i++)
          for(int j=0; j<amount+1; j++)
          {
                int taken=INT_MAX;
         
               if(coins[i-1]<=j)
              {
                taken=dp[i][j-coins[i-1]];
                 if(taken!=INT_MAX)
                  taken++;
              }
        
               int nottaken=dp[i-1][j];

             dp[i][j]=min(taken,nottaken);
          }

         int k=dp[n][amount];
         if(k==INT_MAX) return -1;
         return k;


    }
};
