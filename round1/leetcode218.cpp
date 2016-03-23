
//if x is the same, if both edges are left edges, larger y go first, if both are right edges, smaller y go first; otherwise, left edge for first
//this about this test case: [[0,2,3],[2,5,3]]
class Edge {//well this is a pair, but i want to do practice
    public:
        int x;
        int y;
        bool isLeft = false;
        Edge(int x, int y, bool left) {
            this->x = x;
            this->y = y;
            isLeft = left;
        }
};
    
bool mycmp(const class Edge e1, const class Edge e2) {//if e1 to go first, what condiftion?
        if (e1.x != e2.x)// x can distinguish
            return e1.x < e2.x;
        else {
            if (e1.isLeft == true && e2.isLeft == true)//both left edges
                return e1.y > e2.y;
            else if (e1.isLeft == false && e2.isLeft == false)//both right edges
                return e1.y < e2.y;
            else
                return e1.isLeft;
        }
         
}
    
class Solution {
public:
    //this one is really difficult..
    //Java ref: http://www.programcreek.com/2014/06/leetcode-the-skyline-problem-java/
    //best ref: http://www.cnblogs.com/easonliu/p/4531020.html
    //idea: 
    /*
    分别将每个线段的左边节点与右边节点存到新的vector height中，根据x坐标值排序，然后遍历求拐点。求拐点的时候用一个最大化heap来保存当前的楼顶高度，遇到左边节点，就在heap中插入高度信息，遇到右边节点就从heap中删除高度。分别用pre与cur来表示之前的高度与当前的高度，当cur != pre的时候说明出现了拐点。在从heap中删除元素时要注意，我使用priority_queue来实现，priority_queue并不提供删除的操作，所以又用了别外一个unordered_map来标记要删除的元素。在从heap中pop的时候先看有没有被标记过，如果标记过，就一直pop直到空或都找到没被标记过的值。别外在排序的时候要注意，如果两个节点的x坐标相同，我们就要考虑节点的其它属性来排序以避免出现冗余的答案。且体的规则就是如果都是左节点，就按y坐标从大到小排，如果都是右节点，按y坐标从小到大排，一个左节点一个右节点，就让左节点在前。下面是AC的代码
    */
    
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        if (buildings.empty())
            return res;
            
        vector<class Edge> edges;
        for (auto &x: buildings) {
            class Edge e1 (x[0], x[2], true);
            class Edge e2 (x[1], x[2], false);
            edges.push_back(e1);
            edges.push_back(e2);
        }
        sort(edges.begin(), edges.end(), mycmp);
        //priority_queue<int> heights;//c++ priority queue does not support erase...
        multiset<int> heights;//this is maintained in balanced BST, support erase
        
        int prev = 0;//prev height
        int cur = 0;//current height; if prev != curr, then there is a node
        heights.insert(0);//the last point in the example
        for (auto &e : edges) {
            //cout << "e.x: " << e.x << ' ' << "e.y: " << e.y << endl;
            if (e.isLeft)
                heights.insert(e.y);
            else
                heights.erase(heights.find(e.y));//note that heights.erase(e.y) is WRONG
            cur = *(heights.rbegin());//the last (largest value);
            //cout << "prev is "<< prev << " " << "cur is " << cur << endl;
            //cout << endl;
            if (prev != cur) {
                res.push_back(make_pair(e.x, cur));
                prev = cur;
            }
        }
        
        return res;
    }
};
