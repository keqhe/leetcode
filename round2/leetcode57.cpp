
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<struct Interval> res;
        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }
        
        for (int i = 0; i < intervals.size(); i ++) {
            if (newInterval.start <= intervals[i].start) {
                intervals.insert(intervals.begin()+i, newInterval);
                break;
            }
            if (i == intervals.size() - 1) {
                intervals.push_back(newInterval);
            }
        }
    
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i].start > res.back().end) {
                res.push_back(intervals[i]);
            }
            else {
                res.back().end = max(res.back().end, intervals[i].end);
            }
        }
        return res;
    }
};
