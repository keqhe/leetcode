
struct Edge {
  bool isLeft;
  int x;
  int y;
  Edge(int x_value, int y_value, bool left) : x(x_value), y(y_value), isLeft(left) {};
};

bool myCmp(const Edge & e1, const Edge & e2) {
    if (e1.x != e2.x)   
        return e1.x < e2.x;
    else {
        if (e1.isLeft && e2.isLeft)
            return e1.y > e2.y;
        else if (!e1.isLeft && !e2.isLeft)
            return e1.y < e2.y;
        else
            return e1.isLeft;
    }
}
class Solution {
public:
    //this video really explains the idea behind the skyline problem
    //https://www.youtube.com/watch?v=GSBLe8cKu0s
    //using a priority queue, process edges, when it is left edge insert, when it is right edge erase. Whenever the current max height is changed then <curr_x, curr_max_height> will be a point in the final results
    //the priority queue is implemented using multiset because priority queue in C++ does not support erase operation
    //tier-breaker for some corner case edges
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        if (buildings.empty())
            return res;
        vector<Edge> edges;
        for (auto b : buildings) {
            Edge e1(b[0], b[2], true);
            Edge e2(b[1], b[2], false);
            edges.push_back(e1);
            edges.push_back(e2);
        }
        sort(edges.begin(), edges.end(), myCmp);
        multiset<int> heights;
        heights.insert(0);
        int prev_max_height = 0;
        for (auto &e : edges) {
            if (e.isLeft) {
                heights.insert(e.y);
            }
            else {
                heights.erase(heights.find(e.y));
            }
            int curr_max_height = *heights.rbegin();
            if (curr_max_height != prev_max_height) {
                res.emplace_back(make_pair(e.x, curr_max_height));
                prev_max_height = curr_max_height;
            }
        }
        
        return res;
    }
};
