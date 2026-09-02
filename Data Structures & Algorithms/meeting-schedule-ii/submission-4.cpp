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
      int ans=0;

      for(int i=0; i<meet.size(); i++)
      {
         int room=1;
         for(int j=0; j<meet.size(); j++)
         {
            if(i!=j && meet[i].start>meet[j].start && meet[i].start<meet[j].end) room++;
         }
         ans=max(ans,room);
      }

      return ans;

        
    }
};
