
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool mycmp(const struct Interval n1, const struct Interval n2) {
    return n1.start < n2.start;
} 
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty())
            return 0;
        list<struct Interval> l;
        for (int i = 0; i < intervals.size(); i ++) {
            Interval tmp (intervals[i].start, intervals[i].end);
            l.push_back(tmp);
        }
        l.sort(mycmp);
        for (list<struct Interval>::iterator it = l.begin(); it != l.end(); it ++)
            cout << "(" << it->start << "," << it->end << ")" << " ";
        cout << endl;
        int total = 0;
        int last;
        while (l.size() > 0) {
            total += 1;
            last = l.front().end;
            l.erase(l.begin());
            list<struct Interval>::iterator it = l.begin();
            //cout << "debug" << endl;
            while (it != l.end()) {
                if (it->start >= last) {
                    last = it->end;
                    //cout << last << endl;
                    l.erase(it++);
                }
                else 
                    it ++;
            }
        }
        
        return total;
    }
};
