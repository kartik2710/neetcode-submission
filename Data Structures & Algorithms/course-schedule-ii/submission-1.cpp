class Solution {
public:
    bool dfs(int i, vector<int> adj[], vector<int> &state, vector<int> &ans)
    {
        if(state[i]==1) return true;
        if(state[i]==2) return false;
        state[i]=1;
        for(auto x: adj[i])
        if(dfs(x,adj,state,ans)) return true;

        ans.push_back(i);
        state[i]=2;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
         vector<int> adj[n];
    vector<int> state(n,0);
    for(auto x: pre)
     adj[x[1]].push_back(x[0]);
       
    
    vector<int> ans;
    for(int i=0; i<n; i++)
    {
        if(state[i]==0)
        if(dfs(i,adj,state,ans)) return {};
    }
     reverse(ans.begin(), ans.end());
    return ans;

    }
};
