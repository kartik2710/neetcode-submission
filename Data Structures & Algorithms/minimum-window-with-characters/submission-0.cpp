class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return "";

        vector<int> need(256, 0), have(256, 0);
        for (char c : t) need[c]++;

        int count = 0; // number of chars matched
        int minLen = INT_MAX, start = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            have[s[i]]++;

            if (need[s[i]] != 0 && have[s[i]] <= need[s[i]]) {
                count++;
            }

            // When all characters are matched
            if (count == m) {
                // Shrink from left
                while (need[s[j]] == 0 || have[s[j]] > need[s[j]]) {
                    if (have[s[j]] > need[s[j]]) have[s[j]]--;
                    j++;
                }

                if (i - j + 1 < minLen) {
                    minLen = i - j + 1;
                    start = j;
                }
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
