
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool mycmp(const struct Interval i1, const struct Interval i2) {
     return i1.start < i2.start;
 }
 
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) 
            return true;
        sort(intervals.begin(), intervals.end(), mycmp);
        
        for (int i = 0; i < intervals.size()-1; i ++) {
            if (intervals[i].end > intervals[i+1].start) {
                return false;
            }
        }
        return true;
    }
};
