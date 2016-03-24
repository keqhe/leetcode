
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
    //one idea is greedy, i think in round 1, i used greedy solution
    //anther idea is heap, see: https://leetcode.com/discuss/54571/simple-c-solution-sort-min-heap-greedy
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), mycmp);
        priority_queue<int, vector<int>, std::greater<int>> pq;//min heap
        //[0,10], [0, 10], [10, 20], [15, 30]
        pq.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); i ++) {
            int start_time = intervals[i].start;
            int end_time = pq.top();
            if (start_time >= end_time) {
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
};
