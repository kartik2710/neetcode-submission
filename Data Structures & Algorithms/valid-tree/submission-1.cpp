class Solution {
public:
    void dfs(int i, vector<int> adj[], vector<int> &visited) {
        visited[i] = 1;
        for (auto x : adj[i]) {
            if (!visited[x])
                dfs(x, adj, visited);
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
    
        if (edges.size() != n - 1)
            return false;

        vector<int> adj[n];
        for (auto &x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> visited(n, 0);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                components++;
                if (components > 1)  
                    return false;
            }
        }

        return true; 
    }
};
