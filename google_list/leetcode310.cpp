
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if (n == 0)
            return res;
        if (n == 1) {
            return {0};
        }
        unordered_map<int, unordered_set<int>> adj;
        for (auto e : edges) {
            adj[e.first].insert(e.second);
            adj[e.second].insert(e.first);
        }
        vector<int> leaves;
        for (auto kv : adj) {
            if (kv.second.size() == 1)
                leaves.push_back(kv.first);
        }
        int total = n;
        while (total > 2) {
            total -= leaves.size();
            vector<int> newleaves;
            for (auto x : leaves) {
                int neighbor = *(adj[x].begin());
                adj[neighbor].erase(adj[neighbor].find(x));
                if (adj[neighbor].size() == 1)
                    newleaves.push_back(neighbor);
            }
            leaves = newleaves;
        }
        return leaves;
    }
};
