class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
         vector<int> adj[n];
    vector<int> in(n,0);
    for(auto x: pre)
    {
        adj[x[1]].push_back(x[0]);
        in[x[0]]++;
    }
    queue<int> q;
    for(int i=0; i<n; i++)
    if(in[i]==0)
    q.push(i);

    if(q.size()==0)
    return {};
    vector<int> ans;
    while(!q.empty())
    {
        int ele=q.front();
        ans.push_back(ele);
        q.pop();
        for(auto x: adj[ele])
        {
           in[x]--;
           if(in[x]==0)
           q.push(x);
        }
    }

    if(ans.size()!=n)
    return {};
    return ans;
    }
};
