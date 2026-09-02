class Solution {
public:
    int sol(int i, int j, vector<int> &nums, vector<int> &dp)
    {
      if(i>j) return 0;
      if(dp[i]!=-1) return dp[i];
      int include=nums[i]+sol(i+2,j,nums,dp);
      int exclude=sol(i+1,j,nums,dp);

      return dp[i]=max(include,exclude);
    }
    int rob(vector<int>& nums) {
      int n=nums.size();
      if(n==1) return nums[0];
      if(n==2) return max(nums[0], nums[1]);
       vector<int> dp1(n,-1), dp2(n,-1);
      return max(sol(0,n-2,nums,dp1), sol(1,n-1,nums,dp2));


    }
};
