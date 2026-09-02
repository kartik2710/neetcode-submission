class Solution {
public:
    void sol(int i, vector<int> adj[], vector<int> &visit)
    {
        visit[i]=1;
        for(auto x: adj[i])
        {
            if(visit[x]==0)
            sol(x,adj,visit);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
     for(auto x: edges)
      {
         adj[x[0]].push_back(x[1]);
         adj[x[1]].push_back(x[0]);
      }

      vector<int> visit(n,0);
      int c=0;

      for(int i=0; i<n; i++)
      if(visit[i]==0) {sol(i,adj,visit),c++;}

      return c;
      






    }
};
