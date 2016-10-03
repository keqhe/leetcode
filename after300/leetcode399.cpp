class Solution {
public:
    //https://discuss.leetcode.com/topic/58321/java-ac-solution-with-explanation
    double dfs(unordered_map<string, unordered_map<string, double>>&m, string u, string end, double current, unordered_set<string>&visited) {
        visited.insert(u);
        if (m.find(u) != m.end()) {
            if (u == end)
                return current;
            for (auto& entry : m[u]) {
                string v = entry.first;
                double ratio = entry.second;
                if (visited.find(v) == visited.end()) {
                    double res = dfs(m, v, end, current*ratio, visited);
                    if (res != -1.0) {
                        return res;
                    }
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> m;
        for (int i = 0; i < equations.size(); i ++) {
            string a = equations[i].first;
            string b = equations[i].second;
            double ratio = values[i];
            m[a].insert(make_pair(b, ratio));
            m[b].insert(make_pair(a, 1.0/ratio));
            //m[a].insert(make_pair(a, 1.0));
            //m[b].insert(make_pair(b, 1.0));
        }
        vector<double> res;
        
        for (int i = 0; i < queries.size(); i ++) {
            string s = queries[i].first;
            string e = queries[i].second;
            cout << "current i: " << i << "    ";
            unordered_set<string> visited;
            double ratio = dfs(m, s, e, 1.0, visited);
            res.push_back(ratio);
        }
        return res;
    }
};
