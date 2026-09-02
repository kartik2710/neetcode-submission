class Solution {
public:
void dfs(int i, vector<int> adj[], vector<int> &visited)
{
    visited[i]=1;

    for(auto x: adj[i])
    if(visited[x]==0) dfs(x,adj,visited);
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       
        int n=edges.size();
        int m=n;
        while(n!=-1)
        {
            vector<int> adj[m];

            for(int i=0; i<edges.size(); i++)
            {
                if(i==n-1) continue;

               adj[edges[i][0]-1].push_back(edges[i][1]-1);
              adj[edges[i][1]-1].push_back(edges[i][0]-1);

            }

            n--;
            int count=0;
            vector<int> visited(m,0);

            for(int i=0; i<m; i++)
            if(visited[i]==0)
            {
                dfs(i,adj,visited);
                count++;
            }

            if(count==1) return {edges[n][0], edges[n][1]};




        }
        return {0,0};
    }
};
