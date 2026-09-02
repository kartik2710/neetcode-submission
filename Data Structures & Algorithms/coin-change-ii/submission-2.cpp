class Solution {
public:
int sol(int index, int amount, vector<int>& coins,  vector<vector<int>> &dp)
{
    if(amount==0) return 1;
    if(index<0)   return 0;
    if(dp[index][amount]!=-1) return dp[index][amount];
    

    int include=0, exclude=0;

    if(coins[index]<=amount)
    include=sol(index,amount-coins[index], coins,dp);

    exclude=sol(index-1, amount,coins,dp);

    return dp[index][amount]=include+exclude;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<vector<int>> dp(n+1, vector<int> (amount+1,0));
        for(int i=0; i<n+1; i++) dp[i][0]=1;

        for(int i=1; i<n+1; i++)
        for(int j=0; j<amount+1; j++)
        {
            int include=0, exclude=0;

           if(coins[i-1]<=j) include=dp[i][j-coins[i-1]];
           exclude=dp[i-1][j];
           dp[i][j]=include+exclude;

        }
        return dp[n][amount];
    }
};
