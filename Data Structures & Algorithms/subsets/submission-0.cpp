class Solution {
public:
   vector<vector<int>> ans;
 void sol(int i, vector<int> &nums, vector<int> a)
 {
      if(i==nums.size())
      {
        ans.push_back(a);
        return ;

      }

      a.push_back(nums[i]);
      sol(i+1,nums,a);
      a.pop_back();

      sol(i+1,nums,a);
 }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        
        sol(0, nums, a);
        return ans;
    }
};
