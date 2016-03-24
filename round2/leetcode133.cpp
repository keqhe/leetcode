
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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        queue<struct UndirectedGraphNode*> q;
        unordered_map<struct UndirectedGraphNode*, struct UndirectedGraphNode*> m;
        unordered_set<int> visited;
        
        visited.insert(node->label);
        q.push(node);
        struct UndirectedGraphNode * head = new UndirectedGraphNode(node->label);
        m[node] = head;
        
        while (!q.empty()) {
            struct UndirectedGraphNode * curr = q.front();
            q.pop();
            for (auto p : curr->neighbors) {
                if (visited.find(p->label) == visited.end()) {
                    struct UndirectedGraphNode * tmp = new UndirectedGraphNode(p->label);
                    visited.insert(p->label);
                    q.push(p);
                    m[p] = tmp;
                }
            }
        }
        
        visited.clear();
        
        visited.insert(node->label);
        q.push(node);
        while (!q.empty()) {
            struct UndirectedGraphNode * curr = q.front();
            q.pop();
            for (auto p : curr->neighbors) {
                m[curr]->neighbors.push_back(m[p]);
                if (visited.find(p->label) == visited.end()) {
                    visited.insert(p->label);
                    q.push(p);
                }
            }
        }
        return head;
    }
};
