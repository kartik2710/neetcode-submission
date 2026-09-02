class Solution {
public:
    int sol(int i, int buy, vector<int> &prices)
    {
        if(i>=prices.size()) return 0;

        int profit=0;

        if(buy)
        profit=max(-prices[i]+sol(i+1,0,prices), sol(i+1,1,prices));
        else
        profit=max(prices[i]+sol(i+2,1,prices), sol(i+1,0,prices));

        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return sol(0, 1, prices);
    }
};
