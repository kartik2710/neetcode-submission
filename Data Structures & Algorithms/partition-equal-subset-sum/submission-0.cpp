class Solution {
public:
    bool sol(int i, vector<int> nums, int sum)
    {   
        if(sum==0) return true;
        if(i<0) return false;

        bool include=false;
        if(nums[i]<=sum)
        include=sol(i-1,nums,sum-nums[i]);

        bool exclude=sol(i-1,nums,sum);
        return include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(auto x: nums) sum+=x;
        if(sum%2!=0) return false;

        sum=sum/2;

        return sol(nums.size()-1,nums,sum);


    }
};
