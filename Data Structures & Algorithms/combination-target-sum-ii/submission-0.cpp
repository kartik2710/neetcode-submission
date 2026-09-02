class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int start, vector<int>& can, int target, vector<int>& curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < can.size(); ++i) {
            // Skip duplicates
            if (i > start && can[i] == can[i - 1]) continue;

            if (can[i] > target) break;

            curr.push_back(can[i]);
            backtrack(i + 1, can, target - can[i], curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(), can.end()); // Sort to handle duplicates
        vector<int> curr;
        backtrack(0, can, target, curr);
        return ans;
    }
};
