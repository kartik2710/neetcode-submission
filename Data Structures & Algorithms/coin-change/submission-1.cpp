class Solution {
public:
    int sol(int n, vector<int> coins, int amount)
    {
        if(n==0)
        {
            if(amount%coins[0]==0) return amount/coins[0];
            return INT_MAX;
        }

        int include=INT_MAX;
        if(coins[n]<=amount)
        {include=sol(n,coins,amount-coins[n]);
          if(include!=INT_MAX)
          include+=1;
        }
        int exclude=sol(n-1,coins,amount);

        return min(include,exclude);

    }
    int coinChange(vector<int>& coins, int amount) {
     int k=sol(coins.size()-1, coins, amount);
     return k==INT_MAX? -1: k;
    }
};
