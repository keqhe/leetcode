
class Solution {
public:
    void dfs(vector<list<int>>&adj, int u, vector<int> & visited) {
        visited[u] = 1;
        for (auto v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if (edges.empty())
            return n;
        vector<list<int>> adj(n, list<int>());
        
        for (auto e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
        
        vector<int> visited(n, 0);
        int components = 0;
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                dfs(adj, i, visited);
                components ++;
            }
        }
        return components;
    }
};
