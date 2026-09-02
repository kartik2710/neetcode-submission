class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
       vector<int> *small=&nums1, *large=&nums2;
       if(nums1.size()>nums2.size()) swap(small,large);
       vector<int> &S=*small, &L=*large;

       int m=S.size(), n=L.size();

       int mid=(m+n+1)/2;
       int low=0, high=m;

       while(low<=high)
       {
         int cutS=low+(high-low)/2;
         int cutL=mid-cutS;

         int leftS= cutS==0? INT_MIN: S[cutS-1];
         int leftL= cutL==0? INT_MIN: L[cutL-1];
         int rightS= cutS==m? INT_MAX: S[cutS];
         int rightL= cutL==n? INT_MAX: L[cutL];

         if(leftS<=rightL && leftL<=rightS)
         {
            if((m+n)%2) return(double)max(leftS, leftL);
            else
            {
                int maxy=max(leftS, leftL);
                int miny=min(rightS, rightL);
                return ((double)maxy+(double)miny)/2.0;
            }
         }
         else if(leftS>rightL) high=cutS-1;
         else low=cutS+1;

       }

       return -1;
    }
};
