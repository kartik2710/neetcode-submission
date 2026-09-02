class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans=0,miny=prices[0];
        for(auto x: prices)
        {
            miny=min(miny,x);
            ans=max(ans, x-miny);
        }

        return ans;
    }
};
