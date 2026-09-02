class Solution {
public:
    int sol(int i, vector<int> &nums,vector<int> &dp)
    {
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;

        for(int j=i+1; j<=nums[i]+i; j++)
        {
           int val=sol(j,nums,dp);
           if(val!=INT_MAX) ans=min(ans,val+1);


        }
        return dp[i]=ans;

    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int ans=sol(0,nums,dp);
        
        if(ans==INT_MAX) return false;
        return true;
    }
};
