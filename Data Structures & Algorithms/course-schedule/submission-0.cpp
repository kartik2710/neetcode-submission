class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int> &state)
    {
        if(state[node]==1) return true;
        if(state[node]==2) return false;

        state[node]=1;

        for(auto x: adj[node])
        if(dfs(x,adj,state)) return true;


        state[node]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
         vector<int> state(numCourses,0);
        for(auto x: prerequisites) adj[x[1]].push_back(x[0]);
        
        for(int i=0; i<numCourses; i++)
        {
            if(state[i]==0 && dfs(i,adj,state)) return false;
        }

        return true;
    }
};
