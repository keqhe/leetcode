
class Solution {
public:
    //detect cycle in a undirected graph
    bool dfs(vector<list<int>> & adj, int u, int parent, vector<int> & visited) {
        if (visited[u] == 1)
            return false;//no loop
        if (visited[u] == -1)
            return true;
        visited[u] = -1;
        for (auto x : adj[u]) {
            if (x != parent) {//think about this condition
                if (dfs(adj, x, u, visited))
                    return true;//there is a loop
            }
        }
        visited[u] = 1;
        return false;
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n-1)
            return false;
        vector<list<int>> adj(n, list<int>());
        for (auto e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
        vector<int> visited(n, 0);
        if (dfs(adj, 0, -1, visited))
            return false;
        for (auto b : visited)
            if (!b)
                return false;//more than 1 conencted coponents
        return true;
                
    }
};
