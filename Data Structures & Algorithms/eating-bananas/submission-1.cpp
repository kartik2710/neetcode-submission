class Solution {
public:
    bool check(int mid, vector<int> &piles, int h)
    {
        int count=0;
        for(auto x: piles)
        {
            count+=x/mid;

            if(x%mid) count++;
        }

        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1, right=*max_element(piles.begin(), piles.end());
        int ans=0;
        while(left<=right)
        {
           int mid=left+(right-left)/2;

           if(check(mid, piles,h))
           ans=mid, right=mid-1;
           else left=mid+1;
        }

        return ans;
    }
};
