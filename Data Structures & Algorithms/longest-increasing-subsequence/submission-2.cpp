class Solution {
public:
    int sol(int i, int pre, vector<int> nums,  vector<vector<int>> &dp)
    {
        if(i==nums.size()) return 0;
        if(dp[i][pre+1]!=-1) return dp[i][pre+1];
        int include=0, exclude=0;
        if(pre==-1 || nums[pre]<nums[i])
        include=1+sol(i+1,i,nums,dp);
        exclude=sol(i+1,pre,nums,dp);

        return dp[i][pre+1]=max(include, exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       vector<int> dp(n,1);
        int ans=1;
       for(int i=1; i<n; i++)
       {
          for(int j=0; j<i; j++)
          {
             if(nums[j]< nums[i] && dp[i]<dp[j]+1)
             dp[i]=dp[j]+1;
          }
          ans=max(ans,dp[i]);
       }
       return ans;
       

    }
};
