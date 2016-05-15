
class Solution {
public:
    void dfs(vector<list<int>> &adj, int u, vector<bool> & visited) {
        visited[u] = true;
        for (auto x : adj[u]) {
            if (!visited[x]) {
                dfs(adj, x, visited);
            }
        }
    }
    void bfs(vector<list<int>> &adj, int u, vector<bool> & visited) {
        queue<int> q;
        q.push(u);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            for (auto x : adj[curr]) {
                if (!visited[x]) {
                    q.push(x);
                }
            }
        }
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if (n == 0 || n == 1 || edges.empty())
            return n;
        //vector<list<int>> adj;//this causes problem, think why
        vector<list<int>> adj(n, list<int>());
        for (auto e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                //dfs(adj, i, visited);
                bfs(adj, i, visited);
                count ++;
            }
        }
        return count;
    }
};
