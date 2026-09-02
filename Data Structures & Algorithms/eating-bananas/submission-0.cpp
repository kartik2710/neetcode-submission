class Solution {
public:
bool check(int mid, vector<int>& piles, int h)
{
    int c=0;
    for(int i=0; i<piles.size(); i++)
    {
        c+=piles[i]/mid;
        if(piles[i]%mid) c++;
    }

    return c<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1, j=*max_element(piles.begin(), piles.end());
        int ans=0;
        while(i<=j)
        {
             int mid=i+(j-i)/2;

             if(check(mid,piles,h))
             ans=mid, j=mid-1;
             else i=mid+1;
        }
        return ans;
    }
};
