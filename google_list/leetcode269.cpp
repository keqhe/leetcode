
class Solution {
public:
    bool dfs(unordered_map<char, vector<char>> adj, vector<int> & visited, char u, string & res) {
        if (visited[u] == -1)
            return true;//there is a loop
        if (visited[u] == 1)
            return false;//visited
        visited[u] = -1;
        for (auto v : adj[u]) {
            if (dfs(adj, visited, v, res))
                return true;
        }
        visited[u] = 1;
        res.push_back(u);
        return false;
    }
    string alienOrder(vector<string>& words) {
        string res;
        if (words.empty())
            return res;
        unordered_map<char, vector<char>> adj;
        for (auto word : words) {
            for (auto c : word) {
                if (adj.find(c) == adj.end()) {
                    adj.insert(make_pair(c, vector<char>()));
                }
            }
        }
        
        for (int i = 0; i+1  < words.size(); i ++) {
            string first = words[i];
            string second = words[i+1];
            for (int j = 0; j < min((int)first.length(), (int)second.length()); j ++) {
                if (first[j] == second[j])
                    continue;
                else {
                    adj[first[j]].push_back(second[j]);
                    break;
                }
            }
        }
        
        vector<int> visited(256, 0);
        
        for (auto kv : adj) {
            int key = kv.first;
            if (visited[key] == 0) {
                if (dfs(adj, visited, key, res))
                    return "";//there is a loop
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
