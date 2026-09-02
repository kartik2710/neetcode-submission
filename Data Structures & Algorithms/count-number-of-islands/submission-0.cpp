class DUS
{
   public:
   vector<int> parent;

   void init(int n)
   {
     parent.resize(n);
     for(int i=0; i<n; i++) parent[i]=i;

   }

   int find(int x)
   {
    if(x!=parent[x]) parent[x]=find(parent[x]);
    return parent[x];
   }

   bool merge(int x, int y)
   {
    int fx=find(x), fy=find(y);
    if(fx==fy) return false;
    parent[fx]=fy;
    return true;
   }


};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();

        DUS dus;
        dus.init(n*m);
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        if(grid[i][j]=='1')
        {
           int old=i*m+j;

           for(auto x: dir)
           {
            int newx=x[0]+i, newy=x[1]+j;
            if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]=='1')
             dus.merge(i*m+j, newx*m+newy);
           }

        }
          set<int> st;
        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        if(grid[i][j]=='1') st.insert(dus.find(i*m+j));

        return st.size();


        
    }
};
