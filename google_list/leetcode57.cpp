
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval &t1, const Interval &t2) {
    return t1.start < t2.start;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if (intervals.empty())
            return {newInterval};
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size(); i ++) {
            if (i == 0 || res.back().end < intervals[i].start)
                res.push_back(intervals[i]);
            else {
                //res.back().start = min(intervals[i].start, res.back().start);
                res.back().end = max(intervals[i].end, res.back().end);
            }
        }
        return res;
    }
};
