
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1)
            return {0};
        unordered_map<int, set<int>> adj;
        for (auto e : edges) {
            int a = e.first;
            int b = e.second;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        vector<int> leaves;
        for (int i = 0; i < n; i ++) {
            if (adj[i].size() == 1)
                leaves.push_back(i);
        }
        while (n > 2) {
            n -= leaves.size();
            vector<int> newleaves;
            for (auto x : leaves) {
                for (auto y : adj[x]) {
                    adj[y].erase(adj[y].find(x));
                    if (adj[y].size() == 1)
                        newleaves.push_back(y);
                }
            }
            leaves = newleaves;
        }
        return leaves;
    }
};
