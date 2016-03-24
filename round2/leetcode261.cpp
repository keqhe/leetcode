
class Solution {
public:
    //a nice ref: https://leetcode.com/discuss/82861/share-my-line-dfs-line-bfs-and-clean-union-find-java-solutions
    //ref: https://github.com/keqhe/leetcode/blob/master/graph/graphValidTree.cpp
    //dfs
    /*the following is WRONG, just a small issue but a BIG error...
    bool hasCycle(int parent, int u, vector<list<int>>&adj, vector<bool> & visited) {
        cout << "debug : " << parent << " " << u << " " << visited[u] << endl;
        if (visited[u] == -1)//u is being visited, in the recursion stack
            return true;
        if (visited[u] == 1)
            return false;//already checked u using DFS, it is okay (i.e., no cycle)
        visited[u] = -1;
        for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it ++) {
            if (parent != *it && hasCycle(u, *it, adj, visited))
                return true;
        }
        visited[u] = 1;
        return false;
    }
    */
    //DFS one: 1)no cycle 2) single connected component
    bool hasCycle(int parent, int u, vector<list<int>>&adj, vector<int> & visited) {
        cout << "debug : " << parent << " " << u << " " << visited[u] << endl;
        if (visited[u] == -1)//u is being visited, in the recursion stack
            return true;
        if (visited[u] == 1)
            return false;//already checked u using DFS, it is okay (i.e., no cycle)
        visited[u] = -1;
        for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it ++) {
            if (parent != *it && hasCycle(u, *it, adj, visited))
                return true;
        }
        visited[u] = 1;
        return false;
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n == 0 || n == 1)
            return true;
        vector<list<int>> adj(n, list<int>());
        vector<int> visited(n, false);
        for (auto e : edges) {
            int a = e.first;
            int b = e.second;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        if (hasCycle(-1, 0, adj, visited)) {//starting from vertex 0
            cout << "detected cycle" << endl;
            return false;
        }
        
        for (auto x : visited)
            if (x == 0)
                return false;
        return true;
    }
};
