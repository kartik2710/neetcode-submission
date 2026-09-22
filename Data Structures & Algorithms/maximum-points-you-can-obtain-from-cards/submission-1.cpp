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
       vector<int> preffix(k+1,0), suffix(k+1,0);

       for(int i=1; i<k+1; i++)
       preffix[i]=preffix[i-1]+card[i-1];

       for(int i=1; i<k+1; i++)
       suffix[i]=suffix[i-1]+card[n-i];

       int ans=0;

    //     for(auto x: preffix) cout<<x<<".";
    //    cout<<endl;
       
    //    for(auto x: suffix) cout<<x<<".";
    //    cout<<endl;

       for(int i=0; i<k+1; i++)
       ans=max(ans,preffix[i]+suffix[k-i]);
       return ans;



    }
};