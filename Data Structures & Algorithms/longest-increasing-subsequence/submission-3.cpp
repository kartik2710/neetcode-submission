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
       
       vector<int> ans;
       ans.push_back(nums[0]);

       for(int i=1; i<nums.size(); i++)
       {
          if(ans.back()<nums[i])
          ans.push_back(nums[i]);
          {
            int k=lower_bound(ans.begin(), ans.end(), nums[i])-ans.begin();
            ans[k]=nums[i];
          }
       }
       return ans.size();

    }
};
