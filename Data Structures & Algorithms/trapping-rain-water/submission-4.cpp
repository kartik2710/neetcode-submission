class Solution {
public:
    int trap(vector<int>& arr) {
    int n=arr.size();

   int ans=0;
   
   for(int i=1; i<n-1; i++)
   {
        int left=arr[i];

        for(int j=0; j<i; j++) left=max(left,arr[j]);

        int right=arr[i];

        for(int j=i+1; j<n; j++) right=max(right, arr[j]);

       if(min(right,left)>arr[i])
        ans+=min(right,left)-arr[i];
        
   }
    

    return ans;


    
    
    
    
    
    }


};
