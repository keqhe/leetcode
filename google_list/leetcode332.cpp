
class Solution {
public:
    //topological sort?
    //You may assume all tickets form at least one valid itinerary.
    //[["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
    void dfs(unordered_map<string, multiset<string>> &adj, string curr, vector<string> &res) {
        
        /*for (auto x : adj[curr]) {
            adj[curr].erase(adj[curr].find(x));
            dfs(adj, x, res);
        }*/ //WRONG
        while (adj[curr].size()) {
            auto it = adj[curr].begin();
            auto next = *it;
            adj[curr].erase(it);
            dfs(adj, next, res);
        }
        res.push_back(curr);
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        if (tickets.empty())
            return res;
        unordered_map<string, multiset<string>> adj;
        for (auto p : tickets) {
            auto first = p.first;
            auto second = p.second;
            adj[first].insert(second);
        }
        dfs(adj, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }
};
