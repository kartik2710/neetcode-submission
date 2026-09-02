class Solution {
public:
    bool sol(int i, int parent, vector<int> &visit, vector<int> adj[])
    {
        visit[i]=1;

        for(auto x: adj[i])
        {
            if(visit[x]==0)
            {
                if(sol(x,i,visit,adj)) return true;
            }
            else if(x!=parent)
            return true;
        }

        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {

      vector<int> adj[n];

      for(auto x: edges)
      {
         adj[x[0]].push_back(x[1]);
         adj[x[1]].push_back(x[0]);
      }
       
       vector<int> visit(n,0);
       if(sol(0,-1,visit,adj)) return false;

       for(int i=0; i<n; i++) if(visit[i]==0) return false;

       return true;



    }
};
