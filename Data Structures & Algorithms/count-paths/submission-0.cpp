class Solution {
public:
    int sol(int i, int j)
    {
        if(i<0 || j<0) return 0;
        if(i==0 && j==0) return 1;

        int down=sol(i-1,j);
        int right=sol(i,j-1);

        return down+right;


    }
    int uniquePaths(int n, int m) {
        return sol(n-1,m-1);
        
    }
};
