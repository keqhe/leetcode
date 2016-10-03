
class Solution {
public:
    void dfs(unordered_map<int, vector<int>>&adj, int u, vector<bool>& visited) {
        if (visited[u])
            return;
        visited[u] = true;;
        for (auto v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);
        
        for (auto e : edges) {
            int a = e.first;
            int b = e.second;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int count = 0;
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                dfs(adj, i, visited);
                count ++;
            }
        }
        return count;
    }
};
