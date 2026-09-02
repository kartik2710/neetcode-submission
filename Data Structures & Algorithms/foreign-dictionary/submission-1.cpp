class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> present(26,0);

        for(int i=0; i<words.size(); i++)
        for(auto x: words[i]) present[x-'a']=1;


        vector<int> adj[26];
        vector<int> inorder(26,0);

        for(int i=0; i<words.size()-1; i++)
        {
             string a=words[i];
             string b=words[i+1];

             int k=0,j=0;

             if(a.size()>b.size() && a.substr(0,b.size())==b) return "";
             while(k<a.size() && j<b.size())
             {
                if(a[k]!=b[j])
                {
                    adj[a[k]-'a'].push_back(b[j]-'a');
                    inorder[b[j]-'a']++;
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
            int k=q.front();
            q.pop();
            ans+=char(k+'a');

            for(auto x: adj[k])
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
