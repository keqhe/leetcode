
struct Edge {
  bool isLeft;
  int x;
  int y;
  Edge(int a, int b, bool c) {
      isLeft = c;
      x = a;
      y = b;
  }
};

bool myCmp(const Edge&e1, const Edge&e2) {
    if (e1.x != e2.x) {
        return e1.x < e2.x;
    }
    else {
        if (e1.isLeft && e2.isLeft) {
            return e1.y > e2.y;
        }
        else if (!e1.isLeft && !e2.isLeft) {
            return e1.y < e2.y;
        }
        else {
            return e1.isLeft;
        }
    }
}
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty())
            return {};
        vector<Edge> edges;
        for (auto& b : buildings) {
            int x1 = b[0];
            int x2 = b[1];
            int y = b[2];
            edges.push_back(Edge(x1, y, true));
            edges.push_back(Edge(x2, y, false));
        }
        sort(edges.begin(), edges.end(), myCmp);
        multiset<int> height;
        height.insert(0);
        vector<pair<int, int>> res;
        int prev = 0;
        for (auto& e : edges) {
            if (e.isLeft) {
                height.insert(e.y);
            }
            else {
                height.erase(height.find(e.y));
            }
            int curr = *height.rbegin();
            if (prev != curr) {
                res.push_back(make_pair(e.x, curr));
                prev = curr;
            }
        }
        return res;
    }
};
