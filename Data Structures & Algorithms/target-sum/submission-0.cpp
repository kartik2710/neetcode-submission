class Solution {
public:
    int sol(int i, vector<int>& nums, int target, int sum)
    {
        if(i==nums.size() && sum==target) return 1;
        if(i>=nums.size()) return 0;

        int include=sol(i+1,nums,target, sum+nums[i]);
        int exclude=sol(i+1,nums,target,sum-nums[i]);

        return include+ exclude;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return sol(0, nums, target,0);
    }
};
