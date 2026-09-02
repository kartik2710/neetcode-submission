class Solution {
public:
    int characterReplacement(string s, int k) {
        int j=0, ans=0,maxy=0;
       unordered_map<char,int> mp;

       for(int i=0; i<s.size(); i++)
       {
          mp[s[i]]++;
          maxy=max(maxy,mp[s[i]]);
          
          if(i-j+1-maxy>k)
          mp[s[j]]--, j++;

          ans=max(ans,i-j+1);

       }

       return ans;
    }
};
