
class Solution {
public:
    void dfs(vector<list<int>> & adj, int u, vector<bool> & visited) {
        if (visited[u])//a bit redundant
            return;
        visited[u] = true;
        for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it ++) {
            if (!visited[*it])
                dfs(adj, *it, visited);
        }
    }
    
    void bfs(vector<list<int>>&adj, int u, vector<bool> & visited) {
        if (visited[u])//a bit redudant
            return;
        queue<int> q;
        q.push(u);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            for (list<int>::iterator it = adj[curr].begin(); it != adj[curr].end(); it ++) {
                if (!visited[*it])
                    q.push(*it);
            }
        }
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if (n == 0 || n == 0)
            return n;
        vector<list<int>> adj(n, list<int>());
        for (auto e : edges) {
            int a = e.first;
            int b = e.second;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int count = 0;
        vector<bool> visited(adj.size(), false);
        for (int i = 0; i < adj.size(); i ++) {
            if (!visited[i]) {
                //dfs(adj , i, visited);
                bfs(adj, i, visited);
                count ++;
            }
        }
        return count;
    }
};
