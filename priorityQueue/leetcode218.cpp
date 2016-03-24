
class Edge {
public:     
    int x;
    int y;
    bool isLeft;
    Edge(int a, int b, bool isL) {
        x = a;
        y = b;
        isLeft = isL;
    }    
};
    
bool myCmp(const class Edge e1, const class Edge e2) {
    if (e1.x != e2.x) 
        return e1.x < e2.x; //if e1.x < e2.x, then in sort, e1 goes first
    else {
        if (e1.isLeft && e2.isLeft)
            return e1.y > e2.y;// think why
        else if (!e1.isLeft && !e2.isLeft)
            return e1.y < e2.y;//
        else
            return e1.isLeft;//if e1 is left edge, e1 goes first, otherwise, e2 goes first
    }
}
class Solution {
public:
    //http://www.cnblogs.com/easonliu/p/4531020.html
    //关键词 拐点
    //https://leetcode.com/discuss/61274/17-line-log-time-space-accepted-easy-solution-explanations
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> res;
        if (buildings.empty())
            return res;
        vector<class Edge> edges;
        for (auto x : buildings) {
            class Edge e1 (x[0], x[2], true);
            class Edge e2 (x[1], x[2], false);
            edges.push_back(e1);
            edges.push_back(e2);
        }
        sort(edges.begin(), edges.end(), myCmp);
        int prev = 0;
        int curr = 0;
        multiset<int> height;
        height.insert(0);
        for (auto e : edges) {
            if (e.isLeft)
                height.insert(e.y);
            else
                height.erase(height.find(e.y));
            curr = *height.rbegin();//the current height
            if (curr != prev) {//拐点
                res.push_back(make_pair(e.x, curr));
                prev = curr;
            }
        }
        return res;
    }
};
