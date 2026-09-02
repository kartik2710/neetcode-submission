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
      int n=nums.size();
       
       for(int i=0; i<(1<<n); i++)
       {
         vector<int> a;
         for(int j=0; j<nums.size(); j++)
         {
            if((i & (1<<j))!=0) a.push_back(nums[j]);
         }
         ans.push_back(a);
       }

       return ans;
    }
};
