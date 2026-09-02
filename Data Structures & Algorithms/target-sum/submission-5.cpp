class Solution {
public:
    int sol(int i, vector<int>& nums, int target, int sum,  vector<vector<int>> &dp, int total)
    {
        if(i==nums.size() && sum==target) return 1;
        if(i>=nums.size()) return 0;
        
        if(dp[i][sum+total]!=-1) return dp[i][sum+total];

        int include=sol(i+1,nums,target, sum+nums[i],dp,total);
        int exclude=sol(i+1,nums,target,sum-nums[i],dp,total);

        return dp[i][sum+total]=include+ exclude;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum=0;
        for(auto x: nums) sum+=x;
      
        vector<vector<int>> dp(nums.size(), vector<int>(2*sum+2,-1));

        return sol(0, nums, target,0,dp,sum);
    }
};
