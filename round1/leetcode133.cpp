
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    //this problem, i thought for a while
    //referece1: http://www.programcreek.com/2012/12/leetcode-clone-graph-java/
    //reference2: http://bangbingsyb.blogspot.com/2014/11/leetcode-clone-graph.html
    //key idea: a queue is used to do BFS and a hash table is use to store the map of <orginal,copied>
    
    //the hash table has two purposes: 1)map of <orginal,copied> 2)whether a node has been copied or not;if it has not neen copied, we need to put it into the queue (later we will process it)
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        unordered_map<struct UndirectedGraphNode*, struct UndirectedGraphNode*> m;
        queue<struct UndirectedGraphNode*> q;//node of the orginal graph will be processed in BFS
        
        q.push(node);
        struct UndirectedGraphNode *newgraph = new UndirectedGraphNode(node->label);
        m[node] = newgraph;
        
        while (!q.empty()) {
            struct UndirectedGraphNode * p1 = q.front();
            struct UndirectedGraphNode * p2 = m[p1];//p2 is p1's correponding node
            q.pop();
            for (auto n : p1->neighbors) {
                if (!m.count(n)) {//n has not been copied
                    struct UndirectedGraphNode * n_copy = new UndirectedGraphNode(n->label);
                    m[n] =  n_copy;
                    p2->neighbors.push_back(n_copy);
                    q.push(n);
                }
                else {
                    p2->neighbors.push_back(m[n]);
                }
            }
        }
        
        return newgraph;
    }
};
