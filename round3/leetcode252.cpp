
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool myCmp(const struct Interval i1, const struct Interval i2) {
    return i1.start < i2.start;
}
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), myCmp);
        for (int i = 1; i < intervals.size(); i ++) {
            struct Interval a = intervals[i-1];
            struct Interval b = intervals[i];
            if (b.start < a.end)
                return false;
        }
        return true;
    }
};
