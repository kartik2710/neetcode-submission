class Solution {
public:

    void dfs(string mail,
             unordered_map<string, vector<string>>& mp,
             vector<string>& account,
             set<string>& st) {

        account.push_back(mail);
        st.insert(mail);

        for (auto x : mp[mail]) {
            if (st.find(x) == st.end()) {
                dfs(x, mp, account, st);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, vector<string>> mp;

        // Build graph
        for (int i = 0; i < accounts.size(); i++) {

            for (int j = 2; j < accounts[i].size(); j++) {

                mp[accounts[i][1]].push_back(accounts[i][j]);
                mp[accounts[i][j]].push_back(accounts[i][1]);
            }
        }

        vector<vector<string>> ans;
        set<string> st;

        for (auto x : accounts) {

            string name = x[0];
            string firstMail = x[1];

            if (st.find(firstMail) == st.end()) {

                vector<string> account;

                account.push_back(name);

                dfs(firstMail, mp, account, st);

                sort(account.begin() + 1, account.end());

                ans.push_back(account);
            }
        }

        return ans;
    }
};