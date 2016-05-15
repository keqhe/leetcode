
class Solution {
public:
    bool dfs(unordered_map<char, set<char>> &adj, char u, string & res, vector<int> & visited) {
        if (visited[u-'a'] == 1)
            return false;//no loop
        if (visited[u-'a'] == -1)
            return true;//there is a loop
        visited[u-'a'] = -1;
        for (auto x : adj[u]) {
            if (dfs(adj, x, res, visited) )
                return true;
        }
        visited[u-'a'] = 1;
        res.push_back(u);
        return false;
    }
    string alienOrder(vector<string>& words) {
        if (words.empty())
            return "";
        unordered_set<char> allChars;
        for (auto w : words) {
            for (auto c : w)
                allChars.insert(c);
        }
        unordered_map<char, set<char>> um;
        for (auto c : allChars)
            um[c] = set<char>();
        for (int i = 0; i+1 < words.size(); i ++) {
            string s1 = words[i];
            string s2 = words[i+1];
            for (int j = 0; j < min(s1.length(), s2.length()); j ++) {
                if (s1[j] == s2[j])
                    continue;
                else if (s1[j] != s2[j]) {
                    um[s1[j]].insert(s2[j]);
                    break;
                }
            }
        }
        vector<int> visited(256, 0);
        string res;
        for (auto p : um) {
            char c = p.first;
            if (dfs(um, c, res, visited))
                return "";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
