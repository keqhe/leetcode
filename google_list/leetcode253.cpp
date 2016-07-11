
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool myCmp(const Interval& x, const Interval & y) {
    return x.start < y.start;
}

struct Edge {
  int val;
  bool isLeft;
  Edge(int val, bool isLeft) : val(val), isLeft(isLeft) {}
  bool operator<(const Edge & e) {
    return val < e.val;
  }
};
class Solution {
public:
    //scan line.
    //but can not pass this test case: [[13,15],[1,13]]
    int minMeetingRooms_scanline(vector<Interval>& intervals) {
        if (intervals.empty())
            return 0;
        vector<Edge> edges;
        for (int i = 0; i < intervals.size(); i ++) {
            edges.push_back(Edge(intervals[i].start, true));
            edges.push_back(Edge(intervals[i].end, false));
        }
        sort(edges.begin(), edges.end());
        int count = 0;
        int max_count = 0;
        for (int i = 0; i < edges.size(); i ++) {
            if (edges[i].isLeft) {
                count ++;
            }
            else {
                count --;
            }
            max_count = max(max_count, count); 
        }
        return max_count;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), myCmp);
        //a min heap
        priority_queue<int, vector<int>, std::greater<int>> pq;
        int max_size = 0;
        for (int i = 0; i < intervals.size(); i ++) {
            //this mean current interval can reuse an existing meeting room
            if (!pq.empty() && pq.top() <= intervals[i].start) {
                pq.pop();
            }
            pq.push(intervals[i].end);
            max_size = max(max_size, (int)pq.size());
        }
        return max_size;
    }
};
