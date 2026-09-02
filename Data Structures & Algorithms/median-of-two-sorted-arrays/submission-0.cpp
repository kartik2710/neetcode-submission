class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *small=&nums1, *large=&nums2;

        if(nums1.size()>nums2.size()) swap(small, large);

        vector<int> &S=*small;
        vector<int> &L=*large;
        int m=S.size(), n=L.size();
        int leftSide=(m+n+1)/2;

        int l=0, h=m;
        while(l<=h)
        {
            int cutS=l+(h-l)/2;
            int cutL=leftSide-cutS;
            
            int leftS= (cutS==0)? INT_MIN: S[cutS-1];
            int rightS= (cutS==m)? INT_MAX: S[cutS];
            int leftL= (cutL==0)? INT_MIN: L[cutL-1];
            int rightL= (cutL==n)? INT_MAX: L[cutL];

            if(leftS<=rightL && leftL<=rightS)
            {
                if((m+n)%2)
                return (double)max(leftS, leftL);
                else
                {
                    int maxy=max(leftS, leftL);
                    int miny=min(rightL, rightS);
                    cout<<maxy+miny;
                    return ((double)miny + (double)maxy)/2.0;
                }
            }
            else if(leftS>=rightL) h=cutS-1;
            else l=cutS+1;



        }

        return 0.0;
    }
};
