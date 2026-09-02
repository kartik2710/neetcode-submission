class Solution {
public:
bool check(int mid, vector<vector<int>>& grid)
{
    if(mid<grid[0][0]) return false;
     int n=grid.size(), m=grid[0].size();
     queue<pair<int,int>> q;
     vector<vector<int>> visit(n, vector<int>(m,0));
    visit[0][0]=1;
     q.push({0,0});
      vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
     while(!q.empty())
     {
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if(i==n-1 && j==m-1) return true;

        for(auto x: dir)
        {
            int newx=x[0]+i, newy=x[1]+j;

            if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]<=mid && visit[newx][newy]==0)
            visit[newx][newy]=1, q.push({newx,newy});
        }


     }

     return false;

}
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int low=0, high=0,ans=0;
        for(int i=0; i<n; i++)
        for(int j=0;j<m; j++) high=max(grid[i][j], high);
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(check(mid,grid))
           { ans=mid; high=mid-1;}
            else {low=mid+1;}
        }

        return ans;
    }
};
