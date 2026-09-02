class Solution {
public:
    int sol(int i, int pre, vector<int> nums)
    {
        if(i==nums.size()) return 0;
        int include=0, exclude=0;
        if(pre==-1 || nums[pre]<nums[i])
        include=1+sol(i+1,i,nums);
        exclude=sol(i+1,pre,nums);

        return max(include, exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
       return sol(0,-1,nums);

    }
};
