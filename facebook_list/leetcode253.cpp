
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool myCmp(const Interval& x1, const Interval& x2) {
    return x1.start < x2.start;
}
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), myCmp);
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (int i = 0; i < intervals.size(); i ++) {
            if (!pq.empty() && intervals[i].start >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
};
