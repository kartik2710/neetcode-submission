class Solution {
public:
    int sol(int i, int j, string x, string y)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(x[i]==y[j]) return sol(i-1,j-1,x,y);

        return 1+min({sol(i-1,j,x,y), sol(i,j-1,x,y), sol(i-1,j-1,x,y)});
    }
    int minDistance(string x, string y) {
        int n=x.size();
        int m=y.size();

        return sol(n-1, m-1, x,y);


    }
};
