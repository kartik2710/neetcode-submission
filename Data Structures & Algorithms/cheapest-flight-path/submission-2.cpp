class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        vector<int> dist(n,INT_MAX);

        for(auto x: flights)
        adj[x[0]].push_back({x[1],x[2]});

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        dist[src]=0;
        pq.push({0,{0,src}});

        while(!pq.empty())
        {
            int turn=pq.top().first;
            int cost=pq.top().second.first;
            int node=pq.top().second.second;
            pq.pop();

            if(turn>k) continue;

            for(auto x: adj[node])
            {
                if(dist[x.first]>x.second+cost)
                {
                    dist[x.first]=x.second+cost;
                    pq.push({turn+1,{dist[x.first],x.first}});
                }
            }
        }

        return dist[dst]==INT_MAX? -1: dist[dst];


    }
};
