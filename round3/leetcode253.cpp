
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool myCmp(const struct Interval & x, const Interval & y) {
    return x.start < y.start;
}
class Solution {
public:
    //idea: priority queue or min heap
    //https://github.com/keqhe/leetcode/blob/master/round2/leetcode253.cpp
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), myCmp);
        priority_queue<int, vector<int>, std::greater<int>> pq;//store end of each Interval
        //this is a min heap
        pq.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); i ++) {
            if (!pq.empty() && intervals[i].start >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
};
