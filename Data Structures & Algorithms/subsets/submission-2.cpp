class Solution {
public:
  
    void sol(int i, vector<int> &nums, vector<int> a, vector<vector<int>> &ans)
    {
      if(i==nums.size())
      {
          ans.push_back(a);
          return ;
      }


      a.push_back(nums[i]);
      sol(i+1,nums,a,ans);

      a.pop_back();
      sol(i+1,nums,a,ans);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> a;
         sol(0,nums,a,ans);

        return ans;
    }
};
