class Solution {
public:
    int sol(int i, vector<int>& nums, int target, int sum,  unordered_map<string,int> &mp)
    {
        if(i==nums.size() && sum==target) return 1;
        if(i>=nums.size()) return 0;
        string key=to_string(i)+"_"+to_string(sum);
        if(mp.find(key)!=mp.end()) mp[key];

        int include=sol(i+1,nums,target, sum+nums[i],mp);
        int exclude=sol(i+1,nums,target,sum-nums[i],mp);

        return mp[key]=include+ exclude;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int> mp;

        return sol(0, nums, target,0,mp);
    }
};
