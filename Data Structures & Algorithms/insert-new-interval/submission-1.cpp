class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

         vector<vector<int>> ans;
        for(int i=0; i<intervals.size(); i++)
        {
           if(ans.size()!=0 && ans.back()[1]>=intervals[i][0]) continue;
           for(int j=i+1; j<intervals.size(); j++)
           {
              if(intervals[i][1]>=intervals[j][0])
              {
                intervals[i][0]=min(intervals[i][0],intervals[j][0]);
                intervals[i][1]=max(intervals[i][1],intervals[j][1]);
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
