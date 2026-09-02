class Solution {
public:
struct DUS
{
    vector<int> parent;

    void init(int n)
    {
        parent.resize(n+1);
        for(int i=0; i<n+1; i++) parent[i]=i;
    }

    int find(int x)
    {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool check(int x, int y)
    {
        int parentX= find(x);
        int parentY=find(y);
        if(parentX==parentY) return true;
        parent[parentX]=parentY;
        return false;
    }
};
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DUS d;
        d.init(n);
        for(int i=0; i<edges.size(); i++)
        {
            if(d.check(edges[i][0], edges[i][1]))
            return {edges[i][0], edges[i][1]};
        }

        return {0,0};
        
    }
};
