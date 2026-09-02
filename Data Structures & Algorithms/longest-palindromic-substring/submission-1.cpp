class Solution {
public:
   bool check(int strt, int end, string s)
   {
      while(strt<end)
      {
        if(s[strt]!=s[end]) return false;
        strt++, end--;
      }

      return true;
   }
    string longestPalindrome(string s) {
       int maxy=1,strt=0, n=s.size();
       for(int i=0; i<n; i++)
       for(int j=i; j<n; j++)
       {
         if(check(i,j,s) && j-i+1>maxy)
         {
           maxy=j-i+1;
           strt=i;
         }
       }

       return s.substr(strt,maxy);





    }
};
