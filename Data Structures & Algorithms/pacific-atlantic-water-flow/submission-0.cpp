class Solution {
public:
void dfs(int i,int j,int n,int m, vector<vector<int>>& heights, int curr,   vector<vector<int>> &dp)
{
    if(i<0 || j<0 || i>=n || j>=m || curr>heights[i][j] ||  dp[i][j]==1 ) return ;

    dp[i][j]=1;

    dfs(i+1,j,n,m,heights,heights[i][j],dp);
    dfs(i-1,j,n,m,heights,heights[i][j],dp);
    dfs(i,j-1,n,m,heights,heights[i][j],dp);
    dfs(i,j+1,n,m,heights,heights[i][j],dp);
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();

        vector<vector<int>> dp1(n, vector<int>(m,0));
          vector<vector<int>> dp2(n, vector<int>(m,0));

        for(int i=0; i<n; i++)
        {
            dfs(i,0,n,m,heights,heights[i][0],dp1);
            dfs(i,m-1,n,m,heights,heights[i][m-1], dp2);

        }

        for(int i=0; i<m; i++)
        {
            dfs(0,i,n,m,heights,heights[0][i],dp1);
            dfs(n-1,i,n,m,heights,heights[n-1][i], dp2);
        }
        
        vector<vector<int>> ans;

        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        if(dp1[i][j]==1 && dp2[i][j]==1) ans.push_back({i,j});

        return ans;
    }
};
