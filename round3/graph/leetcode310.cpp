
class Solution {
public:
    //a tree has at most 2 MHTs, it may only has 1
    //the TLE version
    vector<int> findMinHeightTrees_TLE(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if (n == 0)
            return res;
        unordered_map<int, int> inDegree; //first is node, second is this node's in degree
        
        for (auto e : edges) {
            inDegree[e.first] ++;
            inDegree[e.second] ++;
        }
        
        while (inDegree.size() > 2) {
            //cout << inDegree.size() << endl;
            vector<int> deg1;
            for (auto p : inDegree) {
                if (p.second == 1)
                    deg1.push_back(p.first);
            }
            for (auto x : deg1) {
                inDegree.erase(x);
                for (auto e : edges) {
                    if (e.first == x && inDegree.find(e.second) != inDegree.end())
                        inDegree[e.second]--;
                    if (e.second == x && inDegree.find(e.first) != inDegree.end())
                        inDegree[e.first]--;
                }
            }
        }
        for (auto x : inDegree) {
            res.push_back(x.first);
        }
        return res;
    }
    
    //
     vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if (n == 0)
            return res;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        vector<unordered_set<int>> adj(n, unordered_set<int>());
        
        for (auto e : edges) {
            adj[e.first].insert(e.second);
            adj[e.second].insert(e.first);
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
                int neighbor = *(adj[x].begin());
                adj[neighbor].erase(x);
                if (adj[neighbor].size() == 1) {
                    newleaves.push_back(neighbor);
                }
            } 
            leaves = newleaves;
        }
        return leaves;
     }
};
