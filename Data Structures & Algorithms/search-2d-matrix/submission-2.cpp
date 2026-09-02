class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size(), m=matrix[0].size();
       int i=0, j=n*m-1;
       int mid=i+(j-i)/2;
       while(i<=j)
       {
           int element=matrix[mid/m][mid%m];

           if(element==target) return true;
           else if(element>target) j--;
           else i++;
           
            mid=i+(j-i)/2;

       }

       return false;




    }
};
