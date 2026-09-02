class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> st(nums.begin(), nums.end());
    int ans = 0;

    for (int num : st) {
        // Check if num is the start of a sequence
        if (st.find(num - 1) == st.end()) {
            int currentNum = num;
            int currentStreak = 1;

            while (st.find(currentNum + 1) != st.end()) {
                currentNum++;
                currentStreak++;
            }

            ans = max(ans, currentStreak);
        }
    }

    return ans;
    }
};
