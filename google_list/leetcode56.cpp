
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool myCmp(const Interval &e1, const Interval & e2) {
    return e1.start < e2.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.empty())
            return res;
        sort(intervals.begin(), intervals.end(), myCmp);
        res.push_back(intervals.front());
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i].start <= res.back().end) {
                res.back().end = max(res.back().end, intervals[i].end);
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
