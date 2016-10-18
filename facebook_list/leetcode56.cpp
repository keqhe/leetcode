
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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty())
            return {};
        sort(intervals.begin(), intervals.end(), myCmp);
        vector<Interval> tmp;
        for (int i = 0; i < intervals.size(); i ++) {
            if (tmp.empty())
                tmp.push_back(intervals[i]);
            else {
                if (intervals[i].start <= tmp.back().end) {
                    tmp.back().end = max(tmp.back().end, intervals[i].end);
                }
                else {
                    tmp.push_back(intervals[i]);
                }
            }
        }
        return tmp;
    }
};
