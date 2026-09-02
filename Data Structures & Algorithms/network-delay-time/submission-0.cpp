class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];

        for(auto x: times)
        adj[x[0]].push_back({x[1],x[2]});

        vector<int> dist(n+1,INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty())
        {
            int val=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto x: adj[node])
            {
                if(dist[x.first]>x.second+val)
                dist[x.first]=x.second+val, pq.push({dist[x.first],x.first});
                
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
