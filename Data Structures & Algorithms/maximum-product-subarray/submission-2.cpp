class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];

        int miny=nums[0], maxy=nums[0], product=1;

        for(int i=1; i<nums.size(); i++)
        {
            int temp=max({nums[i], nums[i]*miny, nums[i]*maxy});
            miny=min({nums[i], nums[i]*miny, nums[i]*maxy});
            maxy=temp;
            ans=max(ans,temp);
        }

        return ans;
    }
};
