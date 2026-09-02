class Solution {
public:
    int sol(int i, int j, int n, int m, vector<vector<int>>& matrix, int pre)
    {
        if(i<0 || j<0 || i>=n || j>=m || matrix[i][j]<=pre) return 0;

        int top=sol(i+1,j,n,m,matrix,matrix[i][j]);
        int btm=sol(i-1,j,n,m,matrix,matrix[i][j]);
        int left=sol(i,j-1,n,m,matrix,matrix[i][j]);
        int right=sol(i,j+1,n,m,matrix,matrix[i][j]);

        return 1+max({left,right,top,btm});


    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n=matrix.size(), m=matrix[0].size();
        int ans=0;
        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            ans=max(ans,sol(i,j,n,m,matrix,-1));
        }
        return ans;
    }
};
