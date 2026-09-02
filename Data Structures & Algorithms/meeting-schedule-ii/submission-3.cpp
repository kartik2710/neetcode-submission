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
       if (meetings.empty()) return 0;

    int n = meetings.size();
    vector<int> starts, ends;
    // starts.reserve(n);
    // ends.reserve(n);

    for (auto &m : meetings) {
        starts.push_back(m.start);
        ends.push_back(m.end);
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int i = 0, j = 0;
    int used = 0, ans = 0;

    while (i < n && j < n) {
        if (starts[i] < ends[j]) {
            // A new meeting started before the earliest ending one finished
            used++;
            ans = max(ans, used);
            i++;
        } else {
            // One meeting ended → free a room
            used--;
            j++;
        }
    }

    return ans;
        
    }
};
