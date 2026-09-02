class Solution {
public:
    bool sol(int i, vector<int> nums, int sum, vector<vector<int>> &dp)
    {   
        if(sum==0) return true;
        if(i<0) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];

        bool include=false;
        if(nums[i]<=sum)
        include=sol(i-1,nums,sum-nums[i],dp);

        bool exclude=sol(i-1,nums,sum,dp);
        return dp[i][sum]=include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(auto x: nums) sum+=x;
        if(sum%2!=0) return false;

        sum=sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(sum+1,-1));

        return sol(nums.size()-1,nums,sum,dp);


    }
};
