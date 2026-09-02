class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newinter) {
        vector<vector<int>> res;
        int n=inter.size(), i=0;

        while(i<n && inter[i][1]<newinter[0])
        {res.push_back(inter[i]);
        i++;}


        while(i<n && inter[i][0]<=newinter[1])
        {
            newinter[0]=min(inter[i][0], newinter[0]);
            newinter[1]=max(inter[i][1], newinter[1]);
            i++;
        }
        res.push_back(newinter);

        while(i<n)
         res.push_back(inter[i]), i++;

         return res;


    }
};
