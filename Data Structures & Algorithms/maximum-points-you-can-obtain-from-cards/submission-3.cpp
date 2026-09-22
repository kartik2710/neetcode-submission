class Solution {
public:
    int solve(int i, int j, vector<int> &card, int k)
    {
        if(k==0) return 0;

        int frst=card[i]+solve(i+1,j,card,k-1);
        int second=card[j]+solve(i,j-1,card,k-1);

        return max(frst,second);
    }
    int maxScore(vector<int>& card, int k) {
       
       int n=card.size();
       int left=n-k,sum=0,ans=0;

       for(int i=left; i<n; i++)
       sum+=card[i];

       ans=max(ans,sum);

       left=n-k;

       for(int right=0; right<k; right++)
       {
         sum=sum+card[right]-card[left++];

         ans=max(ans,sum);
       }

       return ans;




    }
};