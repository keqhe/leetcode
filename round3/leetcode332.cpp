
class Solution {
public:
    void dfs(unordered_map<string, multiset<string>> & adj, string key, vector<string> & res) {
        while (adj[key].size() > 0) {
            auto it = adj[key].begin();
            string str = *it;
            adj[key].erase(it);//erase it so we do not visit it again
            dfs(adj, str, res);
        }
        res.push_back(key);//it must be after while, think why, think about topological sort
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        if (tickets.empty())
            return res;
        unordered_map<string, multiset<string>> adj;
        for (auto p : tickets) {
            adj[p.first].insert(p.second);
        }
        for (auto p : adj) {
            cout << p.first << " : ";
            for (auto x : p.second)
                cout << x << " ";
            cout << endl;
        }
        dfs(adj, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }
};
