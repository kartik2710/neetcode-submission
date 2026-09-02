class Solution {
public:
    int sol(int i, int buy, vector<int> &prices,  vector<vector<int>> &dp)
    {
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit=0;

        if(buy)
        profit=max(-prices[i]+sol(i+1,0,prices,dp), sol(i+1,1,prices,dp));
        else
        profit=max(prices[i]+sol(i+2,1,prices,dp), sol(i+1,0,prices,dp));

        return  dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));

        for(int i=n-1; i>=0; i--)
        {
            dp[i][1]=max(-prices[i]+dp[i+1][0], dp[i+1][1]);
            dp[i][0]=max(prices[i]+dp[i+2][1], dp[i+1][0]);
        }
        return dp[0][1];
    }
};
