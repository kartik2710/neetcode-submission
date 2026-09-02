class Solution {
public:

   string sol(string s, int l, int r)
         {
            while(l>=0 && r<s.size() && s[l]==s[r])
              l--,r++;

              return s.substr(l+1,r-l-1);
         }
    string longestPalindrome(string s) {
      
     string max_string=s.substr(0,1);
       for(int i=0; i<s.size()-1; i++)
       {
            string odd=sol(s,i,i);
            string even=sol(s,i,i+1);

            if(odd.length()>max_string.length())
            max_string=odd;
            if(even.length()>max_string.length())
            max_string=even;


       }

       return max_string;






    }
};
