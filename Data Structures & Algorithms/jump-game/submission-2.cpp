class Solution {
public:
    int sol(int i, vector<int> &nums,vector<int> &dp)
    {
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;

        for(int j=i+1; j<=nums[i]+i; j++)
        {
           int val=sol(j,nums,dp);
           if(val!=INT_MAX) ans=min(ans,val+1);


        }
        return dp[i]=ans;

    }
    bool canJump(vector<int>& arr) {
         int n = arr.size();

    // array to memoize values
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j <= i + arr[i] && j < n; j++) {
            if (dp[j] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
    }

    // If end cannot be reached.
    if (dp[0] == INT_MAX)
        return 0;

    return 1;



      
    }
};
