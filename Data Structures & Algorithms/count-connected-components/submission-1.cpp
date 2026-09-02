class Solution {
public:

void dfs(int node, vector<int> adj[], vector<int> &visit)
{
    visit[node]=1;

    for(auto x: adj[node])
    {
        if(visit[x]==0)
        {
            visit[x]=1;
            dfs(x,adj,visit);
        }
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> adj[n];
    vector<int> visit(n,0);
      for(auto x: edges)
      {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);

      }
       int c=0;
      for(int i=0; i<n; i++)
      {
        if(visit[i]==0)
        {
            c++;
            dfs(i,adj,visit);
        }
      }


      return c;
    }
};
