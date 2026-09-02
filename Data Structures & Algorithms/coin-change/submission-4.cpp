class Solution {
public:
    int sol(int i, vector<int> &coins, int amount)
    {
        if(amount==0) return 0;
      
        if(i==0)
        {
          //  
            if(amount%coins[0]==0) return amount/coins[0];
            return INT_MAX;

        }

        int include=INT_MAX, exclude=INT_MAX;

        if(coins[i]<=amount)
        {
            include=sol(i,coins,amount-coins[i]);
            if(include!=INT_MAX) include++;
        }

        exclude=sol(i-1,coins,amount);

        return min(include, exclude);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans= sol(coins.size()-1,coins, amount);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
