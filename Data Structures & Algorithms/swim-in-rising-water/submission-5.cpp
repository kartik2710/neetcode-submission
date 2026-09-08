class Solution {
public:
   
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        dist[0][0]=grid[0][0];
       
        priority_queue<pair<int,pair<int,int>>,      vector<pair<int,pair<int,int>>>,
       greater<pair<int,pair<int,int>>> > pq;

       pq.push({grid[0][0],{0,0}});

       while(!pq.empty())
       {
        int val=pq.top().first;
        int i=pq.top().second.first;
        int j=pq.top().second.second;
         pq.pop();

         if(i==n-1 && j==n-1) return val;
        for(auto x: dir)
        {
            int newx=x[0]+i, newy=x[1]+j;
            if(newx>=0 && newy>=0 && newx<n && newy<n && dist[newx][newy]>max(val, grid[newx][newy]))
            {
                dist[newx][newy]=max(val, grid[newx][newy]);
                pq.push({ dist[newx][newy],{newx,newy}});
            }
        }
       }

       return -1;



    }
};
