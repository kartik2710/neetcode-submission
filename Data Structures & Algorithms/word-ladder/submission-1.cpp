class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord)==st.end()) return 0;

        queue<pair<int, string>> q;
        q.push({0,beginWord});

        while(!q.empty())
        {
            int val=q.front().first;
            string word=q.front().second;
            q.pop();

            if(word==endWord) return val+1;

            for(int i=0; i<word.size(); i++)
            {
                char original=word[i];
                for(char c='a'; c<='z'; c++)
                {
                    word[i]=c;

                    if(st.find(word)!=st.end())
                    {
                        q.push({val+1,word});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }


        return 0;
    }
};
