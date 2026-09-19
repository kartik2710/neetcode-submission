class Solution {
public:
    bool containsCycle(int node, vector<int> adj[], vector<int> &state)
    {
        if(state[node]==0) return true;
        if(state[node]==1) return false;

        state[node]=0;
        for(auto x: adj[node])
        if(containsCycle(x,adj,state)) return true;

        state[node]=1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> adj[numCourses];

        for(auto x: pre)
        adj[x[0]].push_back(x[1]);

        vector<int> state(numCourses,-1);

        for(int i=0; i<numCourses; i++)
        {
            if(state[i]==-1 && containsCycle(i,adj,state)) return false;
        }

        return true;
    }
};
