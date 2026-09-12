class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for(int i=0; i<n; i++)
        {
            if(i>0 && ans.back()[1]>=intervals[i][0])
            {
                continue;
            }
            for(int j=i+1; j<n; j++)
            {
               if(intervals[i][1]>=intervals[j][0])
               {
                  intervals[i][1]=max(intervals[j][1], intervals[i][1]);
               }
               else
               {
                break;
               }
            }
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};
