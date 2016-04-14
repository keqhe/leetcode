
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
    //the first dfs only allocate new ndoes
    void dfs1(struct UndirectedGraphNode*node, unordered_map<struct UndirectedGraphNode*, struct UndirectedGraphNode*> &m, unordered_set<int> & visited) {
        visited.insert(node->label);
        struct UndirectedGraphNode * p = new UndirectedGraphNode(node->label);
        m[node] = p;//old and new node mapping
        for (auto x : node->neighbors) {
            if (visited.find(x->label) == visited.end()) {
                dfs1(x, m, visited);
            }
        }
    }
    void dfs2(struct UndirectedGraphNode*node, unordered_map<struct UndirectedGraphNode*, struct UndirectedGraphNode*> &m, unordered_set<int> & visited) {
        visited.insert(node->label);
        for (auto x : node->neighbors) {
            m[node]->neighbors.push_back(m[x]);
        }
        for (auto x : node->neighbors) {
            if (visited.find(x->label) == visited.end()) {
                dfs2(x, m, visited);
            }
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        unordered_map<struct UndirectedGraphNode*, struct UndirectedGraphNode*> m;
        unordered_set<int> visited;
        dfs1(node, m, visited);
        visited.clear();
        dfs2(node, m, visited);
        return m[node];
    }
};
