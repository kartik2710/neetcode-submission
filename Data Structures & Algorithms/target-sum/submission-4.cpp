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

         int n = nums.size();
    int total = 0;
    for (int x : nums) total += x;

    // If target is outside possible sum range
    if (abs(target) > total) return 0;

    vector<vector<int>> dp(n + 1, vector<int>(2 * total + 1, 0));

    // Base case: sum = 0 at index total
    dp[0][total] = 1;

    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= 2 * total; s++) {
            
                int add = s + nums[i - 1];
                int sub = s - nums[i - 1];

                if (add <= 2 * total)
                    dp[i][add] += dp[i - 1][s];
                if (sub >= 0)
                    dp[i][sub] += dp[i - 1][s];
            
        }
    }

    return dp[n][target + total];
    }
};
