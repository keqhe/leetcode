
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
    //this idea is simple to understand, see below
    ///ref: https://leetcode.com/discuss/58464/easy-and-clean-o-n-c-solution
    //O(n) time complexity and O(n) space
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }
        int i = 0;
        for (; i < intervals.size() && intervals[i].end < newInterval.start; i ++) {
            res.push_back(intervals[i]);
        }
        
        //segments that overlap with newInterval
        for (; i < intervals.size() && intervals[i].start <= newInterval.end; i ++) {
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
        }
        res.push_back(newInterval);
        for (; i < intervals.size(); i ++)
            res.push_back(intervals[i]);
            
        return res;
    }
};
