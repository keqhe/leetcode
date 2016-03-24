
class Solution {
public:
    //a nice ref: http://algobox.org/minimum-height-trees/
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        
        vector<int> res;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        
        vector<unordered_set<int>> adj (n,unordered_set<int>());
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
        int total = n;
        while (total > 2) {
            total -= leaves.size();
            vector<int> newleaves;
            for (auto x : leaves) {
                int y = *(adj[x].begin());
                adj[y].erase(x);
                if (adj[y].size() == 1)
                    newleaves.push_back(y);
            }
            leaves = newleaves;
        }
        
        return leaves;
        
        return res;
    }
};
