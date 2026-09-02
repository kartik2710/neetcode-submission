class Solution {
public:
    int trap(vector<int>& arr) {
    int n=arr.size();

   int ans=0;
   
   vector<int> prefix(n,0), suffix(n,0);

  int pre=arr[0];

   for(int i=1; i<n; i++) pre=max(pre, arr[i-1]),prefix[i]=pre;

   int suff=arr[n-1];

   for(int i=n-2; i>=0; i--) suff=max(suff, arr[i+1]), suffix[i]=suff;

   for(int i=1; i<n-1; i++)
   if(min(prefix[i],suffix[i])>arr[i])
   ans+=min(prefix[i],suffix[i])-arr[i];
    

    return ans;


    
    
    
    
    
    }


};
