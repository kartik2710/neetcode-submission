class Solution {
public:
    string foreignDictionary(vector<string>& words) {
         
     vector<int> present(26,0), inorder(26,0);

     for(auto x: words)
     {
        string s=x;
        for(int i=0; i<s.size(); i++)
         present[s[i]-'a']=1;
     }
     
     vector<int> adj[26];

     for(int i=0; i<words.size()-1; i++)
     {
        string a=words[i], b=words[i+1];
         
         if(a.size()>b.size() && a.substr(0,b.size())==b) return "";
        int j=0,k=0;
        while(j<a.size() && k<b.size())
        {
               if(a[j]!=b[k])
               {
                  adj[a[j]-'a'].push_back(b[k]-'a');
                  inorder[b[k]-'a']++;
                  break;
               }
               j++,k++;
        }
     }

     queue<int> q;
     
     for(int i=0; i<26; i++)
     if(present[i] && inorder[i]==0) q.push(i);

     string ans="";
     while(!q.empty())
     {
        int node=q.front();
        q.pop();
        ans+=char(node+'a');

        for(auto x: adj[node])
        {
            inorder[x]--;
            if(inorder[x]==0)
             q.push(x);
        }

     }


     int sum=0;

     for(auto x: present)
     if(x==1) sum++;

     return sum==ans.size()? ans: "";





    }
};
