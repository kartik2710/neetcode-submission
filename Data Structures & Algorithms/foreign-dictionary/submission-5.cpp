class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
        vector<int> present(26,0);
        vector<int> inorder(26,0);
        vector<int> adj[26];
        for(auto x: words)
        {
            string k=x;
            for(int i=0; i<k.size(); i++) present[k[i]-'a']=1;

        }
      
        for(int i=0; i<n-1; i++)
        {
            string a=words[i], b=words[i+1];
            int k=0,j=0;

            if(b.size()<a.size() && a.substr(0,b.size())==b) return "";
            while(k<a.size() && j<b.size())
            {
                if(a[k]!=b[j])
                {
                    adj[a[k]-'a'].push_back(b[j]-'a');
                    inorder[b[j]-'a']++;
                    break;
                }
                k++,j++;
            }
        }

        queue<int> q;

        for(int i=0; i<26; i++)
        if(present[i] && inorder[i]==0) q.push(i);
         
         string ans="";
        while(!q.empty())
        {
            int element=q.front();
            q.pop();
            ans+=char(element+'a');

            for(auto x: adj[element])
            {
                inorder[x]--;
                if(inorder[x]==0) q.push(x);
            }
        }

       

  int totalPresent = accumulate(present.begin(), present.end(), 0);
    if (ans.size() != totalPresent)
        return "";

        return ans;
        
    }
};
