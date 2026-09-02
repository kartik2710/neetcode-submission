
class Solution {
public:
   int manH(vector<int> &a, vector<int> &b)
   {
      return abs(a[0]-b[0])+ abs(a[1]-b[1]);
   }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> visited(n,0);

        

        priority_queue<pair<int,int>, vector<pair<int,int>>,
         greater<pair<int,int>> > pq;

         pq.push({0,0});
         int ans=0;
         while(!pq.empty())
         {
            int val=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(visited[node]==1) continue;

            ans+=val;
            visited[node]=1;

            for(int i=0; i<n; i++)
            {
                if(visited[i]==0)
                {
                    int dist=manH(points[i], points[node]);
                    pq.push({dist,i});

                }
            }
         }

         return ans;
    }
};
