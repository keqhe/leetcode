
class Solution {
public:
    bool dfs(vector<vector<int>>&adj, int u, vector<int>& visited, vector<int>& res) {
        if (visited[u] == 1) //has been visited
            return false;
        if (visited[u] == -1)
            return true;
        visited[u] = -1;
        for (auto v : adj[u]) {
            if (dfs(adj, v, visited, res))
                return true;
        }
        visited[u] = 1;
        res.push_back(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0)
            return {};
        vector<vector<int>> adj(numCourses, vector<int>());
        for (auto p : prerequisites) {
            int a = p.first;
            int b = p.second;
            adj[b].push_back(a);
        }
        vector<int> visited(numCourses, 0);
        vector<int> res;
        for (int i = 0; i < numCourses; i ++) {
            if (visited[i] == 0) {
                //cycle
                if (dfs(adj, i, visited, res))
                    return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
