class Solution {
public:
    int trap(vector<int>& arr) {
    int n=arr.size();

   int ans=0;
   int i=0, j=n-1, lmax=arr[0], hmax=arr[n-1];

   while(i<j)
   {
      lmax=max(lmax,arr[i]);
      hmax=max(hmax,arr[j]);

      if(lmax<hmax) ans+=lmax-arr[i++];
      else ans+=hmax-arr[j--];
   }
    

    return ans;


    
    
    
    
    
    }


};
