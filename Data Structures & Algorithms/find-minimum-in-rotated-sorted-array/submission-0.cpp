class Solution {
public:
    int findMin(vector<int> &nums) {
        int i=0, j=nums.size()-1;

        while(i<=j)
        {
             int m=i+(j-i)/2;
             if(m>0 && nums[m]<nums[m-1]) return nums[m];
             else if(nums[m]>nums[j]) i=m+1;
             else j=m-1;
        }

        return nums[i];
    }
};
