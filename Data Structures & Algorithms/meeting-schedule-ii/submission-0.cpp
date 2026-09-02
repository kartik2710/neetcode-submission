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
    int minMeetingRooms(vector<Interval>& meetings) {
        
        sort(meetings.begin(), meetings.end(), [](const Interval &a, const Interval &b) {
            return a.start < b.start;
        });

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
