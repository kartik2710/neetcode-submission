/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
 
    int minMeetingRooms(vector<Interval>& meet) {
     
     vector<int> strt, end;
     for(auto x: meet) strt.push_back(x.start), end.push_back(x.end);

     sort(strt.begin(), strt.end());
     sort(end.begin(), end.end());

     int i=0,j=0,ans=0,room=0;

     while(i<strt.size())
     {
         if(strt[i]<end[j])
         i++,room++;
         else j++,room--;
         ans=max(ans,room);
     }

     return ans;

        
    }
};
