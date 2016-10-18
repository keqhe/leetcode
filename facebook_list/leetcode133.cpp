
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
            return nullptr;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        unordered_set<UndirectedGraphNode*> visited;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        m[node] = new UndirectedGraphNode(node->label);
        visited.insert(node);
        while (!q.empty()) {
            UndirectedGraphNode* curr = q.front();
            q.pop();
            for (auto* n : curr->neighbors) {
                if (visited.find(n) == visited.end()) {
                    m[n] = new UndirectedGraphNode(n->label);
                    visited.insert(n);
                    q.push(n);
                }
            }
        }
        
        
        visited.clear();
        q.push(node);
        visited.insert(node);
        while (!q.empty()) {
            UndirectedGraphNode* curr = q.front();
            q.pop();
            for (auto* n : curr->neighbors) {
                m[curr]->neighbors.push_back(m[n]);
                if (visited.find(n) == visited.end()) {
                    visited.insert(n);
                    q.push(n);
                }
            }
        }
        
        return m[node];
    }
};
