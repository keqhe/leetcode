
struct Edge {
  int x;
  int y;
  bool isLeft;
  Edge(int x, int y, bool b) {
      this->x = x;
      this->y = y;
      this->isLeft = b;
  }
};
bool myCmp(const struct Edge & e1, const struct Edge & e2) {
    if (e1.x != e2.x)
        return e1.x < e2.x;
    else {
        if (e1.isLeft && e2.isLeft)
            return e1.y > e2.y;
        else if (!e1.isLeft && !e2.isLeft)//both are right edge
            return e1.y < e2.y;
        else 
            return e1.isLeft;//left edge go first
    }
}
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        if (buildings.empty() || buildings[0].empty())
            return res;
        vector<struct Edge> edges;
        for (auto p : buildings) {
            struct Edge e1(p[0], p[2], true);
            struct Edge e2(p[1], p[2], false);
            edges.push_back(e1);
            edges.push_back(e2);
        }
        sort(edges.begin(), edges.end(), myCmp);
        multiset<int> heights;
        heights.insert(0);//the last data point in the contour
        int prev = 0;
        for (int i = 0; i < edges.size(); i ++) {
            if (edges[i].isLeft)
                heights.insert(edges[i].y);
            else {
                heights.erase(heights.find(edges[i].y));
            }
            int curr = *heights.rbegin();
            if (curr != prev) {
                res.push_back(make_pair(edges[i].x, curr));
                prev = curr;
            }
        }
        return res;
    }
};
