class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(), c=matrix[0].size();
        int l=0, h=r*c-1;
        int mid=l+(h-l)/2;

        while(l<=h)
        {
            int ele=matrix[mid/c][mid%c];
            if(ele==target) return true;
            if(ele<target) l=mid+1;
            else h=mid-1;
        mid=l+(h-l)/2;

        }

        return false;
    }
};
