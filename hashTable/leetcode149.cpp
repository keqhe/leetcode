/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    //ref: https://leetcode.com/discuss/18590/sharing-my-simple-solution-with-explanation
    int maxPoints(vector<Point>& points) {
        //the following line has this error: required from ‘struct std::__and_<std::__is_fast_hash<std::hash<std::pair<int, int> > >, std::__detail::__is_noexcept_hash<std::pair<int, int>, std::hash<std::pair<int, int> > > >’
        //think why
        //unordered_map<float, unordered_set<pair<int, int>> > m;
        
        if (points.size() <= 2)
            return points.size();
        int res = 0;
        for (int i = 0; i < points.size(); i ++) {
            unordered_map<double, int> m;
            int sameP = 1;//why we need to get sameP, think about [[0,0],[1,1],[0,0]]
            for (int j = i + 1; j < points.size(); j ++) {
                struct Point p1 = points[i];
                struct Point p2 = points[j];
                if (p1.x == p2.x && p1.y == p2.y)
                    sameP ++;
                else if (p1.x == p2.x) {
                    m[numeric_limits<double>::max()] ++;
                }
                else {
                    //double slope = (p2.y - p1.y) / (p2.x - p1.x);//Note, this is WRONG, think why
                    double slope = (double)(p2.y - p1.y) / (p2.x - p1.x);
                    m[slope] ++;
                }
            }
            int localMax = 0;
            for (auto x : m) {
                localMax = max(localMax, x.second);
            }
            localMax += sameP;
            res = max(res, localMax);
        }
        
        return res;
    }
};
