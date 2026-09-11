class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
       
      
      vector<int> preffix(n,0), suffix(n,0);
      preffix[0]=height[0];
      suffix[n-1]=height[n-1];

      for(int i=1; i<n; i++)
      preffix[i]=max(preffix[i-1],height[i]);

      for(int i=n-2; i>=0; i--)
      suffix[i]=max(suffix[i+1],height[i]);
      int ans=0;

      for(int i=1; i<n-1; i++)
      ans+=min(preffix[i],suffix[i])-height[i];

      return ans;



      
       //return ans;
    }
};
