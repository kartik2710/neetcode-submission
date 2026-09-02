class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int n=grid.size(), m=grid[0].size();

        vector<vector<int> >visit(n, vector<int>(m,0));
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
         if(grid[i][j]==0) q.push({i,j});


         int val=1;


         while(!q.empty())
         {
            int size=q.size();
            while(size--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                if(i-1>=0 && grid[i-1][j]==2147483647 && visit[i-1][j]==0)
                visit[i-1][j]=val, q.push({i-1,j});

                if(i+1<n && grid[i+1][j]==2147483647 && visit[i+1][j]==0)
                visit[i+1][j]=val, q.push({i+1,j});

                if(j-1>=0 && grid[i][j-1]==2147483647 && visit[i][j-1]==0)
                visit[i][j-1]=val, q.push({i,j-1});


                if(j+1<m && grid[i][j+1]==2147483647 && visit[i][j+1]==0)
                visit[i][j+1]=val, q.push({i,j+1});

            } 
            val++;
         }


         for(int i=0; i<n; i++)
         for(int j=0; j<m; j++)
         if(grid[i][j]==2147483647 && visit[i][j]!=0)
         grid[i][j]=visit[i][j];




        
    }
};
