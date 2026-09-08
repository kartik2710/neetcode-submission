class Solution {
public:
    bool check(int mid, vector<vector<int>>& grid)
    {
        int n=grid.size();
        vector<vector<int>> visited(n, vector<int>(n,0));
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0]=1;

        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            if(i==n-1 && j==n-1) return true;
            for(auto x: dir)
            {
                int newx=x[0]+i, newy=x[1]+j;

                if(newx>=0 && newy>=0 && newx<n && newy<n   &&                 visited[newx][newy]==0 && grid[newx][newy]<=mid)
                {
                    visited[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
        }

        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int maxy=0;
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        maxy=max(maxy,grid[i][j]);

        int left=max(grid[0][0],grid[n-1][n-1]), right=maxy,ans=0;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            cout<<mid<<endl;
            if(check(mid,grid)) 
            {cout<<ans<<".";
            ans=mid,right=mid-1;}
            else left=mid+1;
        }

        return ans;
    }
};
