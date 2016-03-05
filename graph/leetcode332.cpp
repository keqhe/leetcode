#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    //this ref is easier to understand: https://leetcode.com/discuss/84848/c-solution-using-dfs
    //the good thing about multiset is that it is already in order
    //also, graph, not only can be represented by vector<list<int>>, it is good to think about 
    //unordered_map<string, multiset<string>>
    void dfs(unordered_map<string, multiset<string>>&adj, string u, vector<string> & res) {
        while (adj[u].size() > 0) {
            auto it = adj[u].begin();
            string next = *it;
            adj[u].erase(it);
            //adj[u].erase(next);//this cause problem for one test case, because if there are duplicates, then it erase multiple elements...
            dfs(adj, next, res);
        }
        res.push_back(u);
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        if (tickets.empty())
            return res;
        unordered_map<string, multiset<string>> adj;
        for (auto e: tickets) {
            adj[e.first].insert(e.second);
        }
        dfs(adj, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
	class Solution sn;
	return 0;
}
