
class Solution {
public:
    //ref:https://leetcode.com/discuss/71763/share-some-thoughts
    //ref:https://leetcode.com/discuss/71980/why-c-is-much-slower-than-java
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 0)
            return {};
        else if (n == 1) {
            return {0};
        }
        
        vector<unordered_set<int>> adj (n, unordered_set<int>());
        for (auto & p : edges) {
            adj[p.first].insert(p.second);
            adj[p.second].insert(p.first);
        }
        
        vector<int> curr;
        vector<int> next;
        
        for (int i = 0; i < adj.size(); i ++) {
            if (adj[i].size() == 1)
                curr.push_back(i);
        }
        
        while (n > 2) {
            for (auto &v : curr) {
                int w = *(adj[v].begin());
                adj[w].erase(v);
                if (adj[w].size() == 1)
                    next.push_back(w);
            }
            n -= curr.size();
            curr.swap(next);
            next.clear();
        }
        
        return curr;
    }
    //the basic idea is to choose each vertex as the source and do bfs, but I meet TLE
    //code is below
    int bfs(int v, vector<list<int>> & adj) {
        int size = adj.size();
        vector<int> color (size, 0);
        vector<int> dist (size, numeric_limits<int>::max());
        queue<int> q;
        q.push(v);
        dist[v] = 0;
        color[v] = 1;
        int height = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it ++) {
                if (color[*it] == 0) {
                    color[*it] = 1;
                    dist[*it] = dist[u] + 1;
                    q.push(*it);
                    if (dist[*it] > height)
                        height = dist[*it];
                }
            }
        }
        
        return height;
    }
    vector<int> findMinHeightTrees_mine(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if (n == 0)
            return res;
        vector<list<int>> adj (n, list<int>());
        for (int i = 0; i < edges.size(); i ++) {
            int a = edges[i].first;
            int b = edges[i].second;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> heights (n, 0);
        int minHeight = numeric_limits<int>::max();
        for (int i = 0; i < n; i ++) {
            heights[i] = bfs(i, adj);
            minHeight = min(minHeight, heights[i]);
        }
        
        for (int i = 1; i < n; i ++) {
            if (heights[i] == minHeight)
                res.push_back(i);
        }
        return res;
    }
};
