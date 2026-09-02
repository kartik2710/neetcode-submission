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
         int curr=0, maxy=0, count=0;

         for(int i=0; i<n; i++)
         {
            maxy=max(maxy,arr[i]+i);
            if(maxy>=arr.size()-1) return count+1;

            if(i==curr)
            {
                if(i==maxy) return false;

                curr=maxy;
                count++;
            }
         }

         return 0;

      

      
    }
};
