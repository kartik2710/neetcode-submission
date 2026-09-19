class Solution {
public:
bool containsCycle(int node, vector<int> adj[], vector<int> &state, vector<int> &ans)
    {
        if(state[node]==0) return true;
        if(state[node]==1) return false;

        state[node]=0;

        for(auto x: adj[node])
        if(containsCycle(x,adj,state,ans)) return true;

        ans.push_back(node);
        state[node]=1;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
         vector<int> adj[numCourses];

        for(auto x: pre)
        adj[x[1]].push_back(x[0]);

        vector<int> state(numCourses,-1);
        vector<int> ans;
        for(int i=0; i<numCourses; i++)
        {
            if(state[i]==-1 && containsCycle(i,adj,state,ans)) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
