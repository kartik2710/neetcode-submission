class Solution {
public:
   vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
   vector<string> ans;


    void sol(int i,string digits, string s)
    {
        if(i==digits.size())
        {
            ans.push_back(s);
            return ;
        }

        int nums=digits[i]-'0';
        string val=mapping[nums];

        for(int j=0; j<val.size(); j++)
        {
            s.push_back(val[j]);
            sol(i+1,digits,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
   
    if(digits.size()==0) return {};

    sol(0,digits,"");

    return ans;


    }
};
