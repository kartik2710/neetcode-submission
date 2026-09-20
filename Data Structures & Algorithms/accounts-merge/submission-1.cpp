class DUS
{
   public:
   vector<int> parent, rank;
   void init(int n)
   {
       parent.resize(n,0);
       rank.resize(n,0);
       
       for(int i=0; i<n; i++) parent[i]=i;
   }
   
   int find(int x)
   {
       if(x!=parent[x]) parent[x]=find(parent[x]);
       
       return parent[x];
   }
   
   bool merge(int x, int y)
   {
       int fx=find(x), fy=find(y);
       if(fx==fy) return false;
       
       if(rank[fx]<rank[fy]) parent[fx]=fy;
       else if(rank[fy]<rank[fx]) parent[fy]=fx;
       else
       {
           parent[fy]=fx;
           rank[fx]++;
       }
       return true;
   }
};

class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
    // code here
        int n=arr.size();
        DUS dus;
        dus.init(n);
        
        unordered_map<string,int> mp;
        
        for(int i=0; i<arr.size(); i++)
        for(int j=1; j<arr[i].size(); j++)
        {
            if(mp.find(arr[i][j])==mp.end())
            mp[arr[i][j]]=i;
            else
            dus.merge(i,mp[arr[i][j]]);
        }
        
       vector<string> adj[n];
       
       for(auto &it : mp)
       {
           int node=dus.find(it.second);
           adj[node].push_back(it.first);
           
       }
       
       vector<vector<string>> accounts;
       
       for(int i=0; i<n; i++)
       {
           if(adj[i].size()==0)
           continue;
           
           vector<string> account;
           
           account.push_back(arr[i][0]);
           
           for(auto &it: adj[i])
            account.push_back(it);
            
            sort(account.begin()+1, account.end());
            
            accounts.push_back(account);
            
           
       }
       
       return accounts;
        
        
    }

};