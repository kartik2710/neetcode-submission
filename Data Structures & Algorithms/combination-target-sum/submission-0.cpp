class Solution {
public:
    vector<vector<int>> ans;
    void sol(int i, vector<int> &nums, int target, vector<int> a)
    {
        
         if(target==0)
         {
            ans.push_back(a);
            return ;
         }
          if(i<0) return;

         if(nums[i]<=target)
         {
            a.push_back(nums[i]);
            sol(i,nums,target-nums[i],a);
            a.pop_back();
         }

         sol(i-1,nums,target,a);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<int> a;
        sol(nums.size()-1,nums, target,a);
        return ans;
        
    }
};
