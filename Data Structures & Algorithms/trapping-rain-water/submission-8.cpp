class Solution {
public:
    int trap(vector<int>& height) {
        
    int n=height.size();
    int ans=0;
    int left=0, right=n-1,preffix=height[0], suffix=height[n-1];
    while(left<right)
    {
       preffix=max(height[left],preffix);
       suffix=max(height[right], suffix);

       if(preffix<suffix) ans+=preffix-height[left++];
       else ans+=suffix-height[right--];

    }

    return ans;
    }
};
