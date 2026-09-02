class DSU
{
    public:
    vector<int> parent;
    DSU(int n)
    {
       parent.resize(n+1);
      for(int i=0; i<n+1; i++) parent[i]=i;
    }

    int find(int x)
    {
        if(parent[x]!=x)
        parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y)
    {
        int rx=find(x), ry=find(y);
        if(rx==ry) return true;

        parent[rx]=ry;
        return false;
    }


};
class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n=edges.size();
       DSU dsu(n);

       for(int i=0; i<edges.size(); i++)
       {
          if(dsu.unite(edges[i][0], edges[i][1]))
          return {edges[i][0], edges[i][1]};
       }

       return {0,0};
       
    }
};
