#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    //topologicial sort
    bool dfs(unordered_map<char, set<char>> & adj, char u, vector<int> & visited, string & res) {
        if (visited[u] == -1)
            return true;//has a cycle
        if (visited[u] == 1)
            return false;
        visited[u] = -1;
        for (auto it = adj[u].begin(); it != adj[u].end(); it ++) {
            if (dfs(adj, *it, visited, res))
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
        unordered_map<char, set<char>> adj;
        //initially i made a mistake, see the following
        /*
        for (auto w : words) {
            for (int i = 0; i + 1< w.length(); i ++) {
                if (w[i] != w[i+1])
                    adj[w[i]].insert(w[i+1]);
            }
        }*/
        unordered_set<char> allChars;
        for (auto w : words) {
            for (auto c : w)
                allChars.insert(c);
        }
        
        for (int i = 0; i < words.size() -1; i ++) {
            string a = words[i];
            string b = words[i+1];
            for (int k = 0; k < min(a.length(), b.length()); k ++) {
                if (a[k] != b[k]) {
                        adj[a[k]].insert(b[k]);
                        break;//this break is important, think why
                }
            }
        }
        vector<int> visited(256, false);
        for (auto c : allChars) {
            if (dfs(adj, c, visited, res)) {
                string tmp;
                return tmp;
            }
        }
        cout << "no loop" << endl;
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
	class Solution sn;	
	return 0;
}
