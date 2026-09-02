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
  static bool comp(const Interval &a, const Interval &b) {
    return a.start < b.start;
}
    int minMeetingRooms(vector<Interval>& meetings) {
       sort(meetings.begin(), meetings.end(), comp);

      priority_queue<int, vector<int>, greater<int>> pq; 

        for (auto &m : meetings) {
            if (!pq.empty() && pq.top() <= m.start) {
                pq.pop(); 
            }
            pq.push(m.end); 
        }
        return pq.size();
    }
};
