
class Solution {
public:
    //bfs or dfs
    void dfs(int u, vector<bool> & visited, vector<list<int>> & adj) {
        /*redundant
        if (visited[u])
            return;
        */
        visited[u] = true;
        for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it ++) {
            if (!visited[*it]) {
                dfs(*it, visited, adj);
            }
        }
    }
    
    void bfs(int u, vector<bool> & visited, vector<list<int>> & adj) {
        visited[u] = true;
        
        queue<int> q;
        q.push(u);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            //cout << "curr: " << curr << endl;
            for (list<int>::iterator it =adj[curr].begin(); it != adj[curr].end(); it ++) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<list<int>> adj (n, list<int>());
        for (auto & x : edges) {
            adj[x.first].push_back(x.second);
            adj[x.second].push_back(x.first);
        }
        
        vector<bool> visited(n, false);
        int total = 0;
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                //dfs(i, visited, adj);
                bfs(i, visited, adj);
                total ++;
            }
        }
        return total;
    }
};
