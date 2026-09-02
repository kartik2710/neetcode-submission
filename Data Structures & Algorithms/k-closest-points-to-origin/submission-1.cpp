class Solution {
public:
  int eucDist(vector<int> &a)
  {
    return a[0]*a[0] + a[1]*a[1];
  }
   int partition(int left, int right,vector<vector<int>>& points )
   {
    vector<int> pivot=points[right];
    int i=left;
    for(int j=left; j<right; j++)
    {
        if(eucDist(points[j])<=eucDist(pivot))
        swap(points[i], points[j]), i++;
    }

    swap(points[right], points[i]);
    return i;
   }
    void sol(int left, int right, vector<vector<int>>& points, int k)
    {
        if(left<=right)
        {
            int pivotIndex=partition(left,right,points);
            int leftSide=pivotIndex-left+1;

            if(leftSide==k) return ;
            if(leftSide>k) sol(left,pivotIndex-1, points,k);
            else sol(pivotIndex+1,right, points,k-leftSide);
        }
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
     sol(0, points.size()-1, points,k);

     return vector<vector<int>> (points.begin(), points.begin()+k);

        
        
    }
};
