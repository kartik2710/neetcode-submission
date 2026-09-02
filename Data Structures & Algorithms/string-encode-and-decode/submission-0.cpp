#include <bits/stdc++.h>
class Solution {
public:

    string encode(vector<string>& strs) {
      string s;
      for(auto x: strs)
      s+=to_string(x.size())+"#"+x;
     

     cout<<s;
     return s;
    }

    vector<string> decode(string s) {
       vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, len);
            result.push_back(word);
            i = j + 1 + len;
        }
        return result;



    }
};
