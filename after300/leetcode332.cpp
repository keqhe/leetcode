
class Solution {
public:
    //i feel this reference is much better
    //https://discuss.leetcode.com/topic/36411/very-straightforward-dfs-solution-with-detailed-explanations
    
    //the following code is actually topological sort, i feel; relies on the fact that there must be a solution there.
    //this guy explains why the following code works:
    //see https://discuss.leetcode.com/topic/36370/short-ruby-python-java-c
    void dfs(unordered_map<string, multiset<string>> &adj, string curr, vector<string> &res) {
        
        /*for (auto x : adj[curr]) {
            adj[curr].erase(adj[curr].find(x));
            dfs(adj, x, res);
        }*/ //WRONG
        cout << curr << " ";
        while (adj[curr].size() > 0) {//if curr is not in adj, it is still okay, think why
            auto it = adj[curr].begin();
            auto next = *it;
            //cout << next << endl;
            adj[curr].erase(it);
            dfs(adj, next, res);
        }
        res.push_back(curr);
    }
    bool dfs2(unordered_map<string, multiset<string>>& adj, int tickets, vector<string>& res, string curr, unordered_map<string, int>& total) {
        for (auto next : adj[curr]) {
            if (total[curr+next] > 0) {
                res.push_back(next);
                if (res.size() == tickets+1) {
                    return true;
                }
                total[curr+next] --;
                if(dfs2(adj, tickets, res, next, total)) {
                    return true;
                }
                total[curr+next] ++;
                res.pop_back();
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> adj;
        unordered_map<string, int> total;
        for (auto p : tickets) {
            adj[p.first].insert(p.second);
            total[p.first+p.second] ++;
        }
        vector<string> res;
        /* method 2
        dfs(adj, "JFK", res);
        reverse(res.begin(), res.end());
        */
        //method 1, which is plain dfs
        res.push_back("JFK");
        dfs2(adj, tickets.size(), res, "JFK", total);
        return res;
    }
};
