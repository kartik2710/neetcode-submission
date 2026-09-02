class Solution {
public:
   int sol(int index, int end, vector<int> &nums, vector<int> &dp)
   {
      if(index<end) return 0;
      if(dp[index]!=-1) return dp[index];
      int taken=nums[index]+sol(index-2,end,nums,dp);
      int nottaken=0+sol(index-1,end,nums,dp);

      return  dp[index]=max(taken,nottaken);
   }
    int rob(vector<int>& nums) {
        int n = nums.size();
    if (n == 1) return nums[0];

    int first = 0, sec = 0;
    int ans1 = 0, ans2 = 0;

  
    for (int i = 0; i <= n - 2; i++) {
        int temp = first;
        first = max(sec + nums[i], first);
        sec = temp;
    }
    ans1 = max(first, sec);

    // Case 2: Rob from house 1 to n-1 (exclude first house)
    first = 0; sec = 0;
    for (int i = 1; i <= n - 1; i++) {
        int temp = first;
        first = max(sec + nums[i], first);
        sec = temp;
    }
    ans2 = max(first, sec);

    return max(ans1, ans2);


    }
};
