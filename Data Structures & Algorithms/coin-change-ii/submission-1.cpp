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

        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        return sol(coins.size()-1,amount,coins,dp);
    }
};
