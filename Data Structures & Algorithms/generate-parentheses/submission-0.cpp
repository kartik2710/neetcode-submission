class Solution {
public:
    void sol(int open, int close, int n, vector<string>& ans, string s)
    {
        if(open == n && close == n)
        {
            ans.push_back(s);
            return;
        }

        if(open < n)
            sol(open + 1, close, n, ans, s + "(");

        if(close < open)
            sol(open, close + 1, n, ans, s + ")");
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        sol(0, 0, n, ans, "");

        return ans;
    }
};
