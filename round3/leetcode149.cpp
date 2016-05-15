
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
    int maxPoints(vector<Point>& points) {
        if (points.size() < 2)
            return points.size();
        //fix one point and find the number of points on the same line
        int maxCnt = 0;
        for (int i = 0; i < points.size(); i ++) {
            unordered_map<double, int> slope;//slope 
            int same = 1;
            for (int j = i + 1; j < points.size(); j ++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y)
                    same ++;
                else {
                    if (points[i].x == points[j].x) {
                        slope[numeric_limits<double>::max()] ++;
                    }
                    else {
                        double curr_slope = (double)(points[j].y-points[i].y) / (double)(points[j].x-points[i].x);
                        slope[curr_slope] ++;
                    }
                }
            }
            maxCnt = max(maxCnt, same);//need this because the following for loop may be not excuted, because slope might be empty, test case: [[0,0],[0,0]]
            for (auto p : slope) {
                //cout << same << endl;
                maxCnt = max(maxCnt, p.second+same);
            }
        }
        return maxCnt;
    }
};
