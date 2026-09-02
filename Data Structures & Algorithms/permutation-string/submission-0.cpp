class Solution {
public:
bool check(vector<int> &pat, vector<int> &text)
{
    for(int i=0; i<26; i++)
    if(pat[i]!=text[i])
    return false;

    return true;
}
    bool checkInclusion(string s1, string s) {
        int n=s1.size(), m=s.size();
        vector<int> pat(26,0), text(26,0);

        for(auto x: s1) pat[x-'a']++;
        
        int right=0,left=0;
        for(right=0; right<n; right++)
        text[s[right]-'a']++;

        if(check(text,pat)) return true;

        for(; right<m; right++)
        {
            text[s[left]-'a']--;
            text[s[right]-'a']++;

            left++;
            if(check(text,pat)) return true;

        }


        return false;

        
    }
};
