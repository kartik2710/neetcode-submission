class Solution {
public:
   int sol(int index, int end, vector<int> &nums, vector<int> &dp)
   {
      if(index<end) return 0;
      if(dp[index]!=-1) return dp[index];
      int taken=nums[index]+sol(index-2,end,nums,dp);
      int nottaken=0+sol(index-1,end,nums,dp);

      return  dp[index]=max(taken,nottaken);
   }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
         return max(sol(n-2,0,nums,dp1), sol(n-1,1,nums,dp2));
    }
};
