class Solution {
public:
    bool check(long long mid,vector<int>& weights, int days )
    {
        int count=1;
        long long sum=0;

        for(auto x: weights)
        {
            if(x+sum<=mid)
            sum+=x;
            else
            sum=x,count++;
        }
       
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long left=*max_element(weights.begin(), weights.end());
        long long right=accumulate(weights.begin(), weights.end(),0LL);
        long long ans=0;

        if(weights.size()<days) return -1;

        while(left<=right)
        {
            long long mid=left+(right-left)/2;

            if(check(mid,weights,days))
            ans=mid, right=mid-1;
            else
            left=mid+1;
            cout<<ans<<".";
        }

        return ans;


    }
};