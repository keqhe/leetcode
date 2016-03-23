
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
    //ref: https://leetcode.com/discuss/73998/c-code-with-hashmap-beating-96%25-others
    //dea: For one single point, we calculate the slopes to each of others and store them in a hash map. Take care of the case INT_MAX and duplicate.
    int maxPoints(vector<Point>& points) {
        if (points.empty())
            return 0;
        unordered_map<double,int> ht;
        int res = 0;
        
        for (int i = 0; i < points.size(); i ++) {
            ht.clear();
            int dup = 1;
            
            for (int j = i + 1; j < points.size(); j ++) {//why j = i+1? point[i] and point[j]
                int x1 = points[i].x;
                int x2 = points[j].x;
            
                int y1 = points[i].y;
                int y2 = points[j].y;
                
                double slope;
                if (x1 == x2 && y1 == y2) {//dup
                    dup ++;
                }
                else if (x1 == x2 && y1 != y2) {
                    slope = numeric_limits<int>::max();
                    ht[slope] ++;
                }
                else {
                    
                    slope = (double) (y2-y1)/(x2-x1);//error prone..
                    ht[slope] ++;
                }
            }
            
            res = max(res, dup); //in case no element in hash table
            for (auto & e: ht) {
                res = max(res, dup + e.second);
            }
        }
        return res;
    }
};
