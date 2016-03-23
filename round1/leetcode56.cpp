
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool intervalCmp(struct Interval & v1, struct Interval & v2) {
        return v1.start < v2.start;
    }
    
class Solution {
public:
    //https://leetcode.com/discuss/71636/simple-c-implementation-using-vector-operations
    
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty() || intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), intervalCmp);
        
        vector<Interval> res;
        res.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i].start > res.back().end) {
                res.push_back(intervals[i]);
            }
            else {
                int maxEnd = max(res.back().end, intervals[i].end);
                int minStart = min(res.back().start, intervals[i].start);
                struct Interval tmp(minStart, maxEnd);
                res.pop_back();
                res.push_back(tmp);
            }
        }
        
        return res;
    }
};
