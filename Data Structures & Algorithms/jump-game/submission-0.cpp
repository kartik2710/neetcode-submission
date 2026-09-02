class Solution {
public:
    int sol(int i, vector<int> &nums)
    {
        if(i>=nums.size()-1) return 0;
        int ans=INT_MAX;

        for(int j=i+1; j<=nums[i]+i; j++)
        {
           int val=sol(j,nums);
           if(val!=INT_MAX) ans=min(ans,val+1);


        }
        return ans;

    }
    bool canJump(vector<int>& nums) {
        int ans=sol(0,nums);
        if(ans==INT_MAX) return false;
        return true;
    }
};
