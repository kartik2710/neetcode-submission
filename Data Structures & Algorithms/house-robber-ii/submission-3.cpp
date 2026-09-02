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
        int n = nums.size();
     if (n == 1) return nums[0];
     if(n==2) return max(nums[0], nums[1]);

        vector<int> dp1(n,0), dp2(n,0);
     dp1[0]=nums[0];
     dp1[1]=max(nums[0],nums[1]);
   
     for(int i=2; i<=n-2; i++)
     {
        int taken=nums[i]+dp1[i-2];
        int nottaken=0+dp1[i-1];
        dp1[i]=max(taken,nottaken);
     }

     dp2[0]=0;
     dp2[1]=nums[1];
     for(int i=2; i<=n-1; i++)
     {
        int taken=nums[i]+dp2[i-2];
        int nottaken=0+dp2[i-1];
        dp2[i]=max(taken,nottaken);
     }

     return max(dp2[n-1],dp1[n-2]);


    


    }
};
