
class Solution {
public:
    bool dfs(vector<list<int>>&adj, int u, int parent, vector<int>&visited) {
        if (visited[u] == 1)
            return false;//visited, no loop
        if (visited[u] == -1)
            return true;//visited, loop detected
        visited[u] = -1;
        for (auto v : adj[u]) {
            //if (v != parent && !visited[v]) // this is WRONG
            if (v != parent) {
                if (dfs(adj, v, u, visited))
                    return true;
            }
        }
        visited[u] = 1;
        return false;
    }
    //one connected component, and no cycle
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n == 0)
            return true;
        vector<list<int>> adj(n);
        for (auto e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
        
        vector<int> visited(n, 0);
        int components = 0;
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                if(dfs(adj, i, -1, visited))
                    return false;
                components ++;
            }
        }
        return components == 1;
    }
};
