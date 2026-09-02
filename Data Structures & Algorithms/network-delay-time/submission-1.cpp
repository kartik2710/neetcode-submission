class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      

        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;

        for(int i=0; i<n-1; i++)
        {
            for(auto x: times)
            {
               if(dist[x[0]]!= INT_MAX && dist[x[1]]>dist[x[0]]+x[2])
               dist[x[1]]=dist[x[0]]+x[2];
            }
        }

        int ans=0;
        dist[0]=0;
        for(auto x: dist)
        {if(x==INT_MAX) return -1;
        else ans=max(ans,x);}

        return ans;







    }
};
