
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
    //using BFS or DFS to generate new nodes
    // Then using hash table.
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return nullptr;
        queue<UndirectedGraphNode*> q;
        unordered_set<UndirectedGraphNode*> visited;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode* curr = q.front();
            q.pop();
            UndirectedGraphNode * newnode = new UndirectedGraphNode(curr->label);
            m[curr] = newnode;
            visited.insert(curr);
            for (auto x : curr->neighbors) {
                if (visited.find(x) == visited.end()) {
                    q.push(x);
                }
            }
        }
        
        for (auto kv : m) {
            auto curr = kv.first;
            for (auto x : curr->neighbors) {
                m[curr]->neighbors.push_back(m[x]);
            }
        }
        return m[node];
    }
};
