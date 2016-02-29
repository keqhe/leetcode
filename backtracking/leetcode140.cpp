#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    //this seems to be natural to use backtracking, the following version is TLE for one test case
    void backtracking(string s, int index, string path, unordered_set<string>&wordDict, vector<string>& res) {
        if (index == s.length()) {
            path.pop_back();
            res.push_back(path);
            return;
        }
        
        for (auto x : wordDict) {
            int xlen = x.length();
            if (s.substr(index, xlen) == x) {
                backtracking(s, index+xlen, path+x+" ", wordDict, res);
            }
        }
    }
    
    //the TLE problem resolved by using cache to avoid duplicated compuations
    vector<string> dfs_cache(string s, unordered_set<string>&wordDict, unordered_map<string, vector<string>> & m) {
        if (m.find(s) != m.end())
            return m[s];
        vector<string> res;
        if (s.empty()) {
            //res.push_back("");
            return res;
        }
        for (auto x : wordDict) {
            int xlen = x.length();
            if (x == s) {
                res.push_back(x);
            }
            else if (s.substr(0, xlen) == x) {
                vector<string> left = dfs_cache(s.substr(xlen), wordDict, m);
                for (auto str : left) {
                    res.push_back(x+" "+str);
                }
            }
        }
        m[s] = res;
        return res;
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if (s.empty() || wordDict.empty())
            return res;
        //backtracking(s, 0, "", wordDict, res);
        unordered_map<string, vector<string>> m;
        return dfs_cache(s, wordDict, m);
    }
    
    //how to use dp to solve this problem?
    //well, i think backtracking (dfs) with cache is good enough, and I think DP is too complicated 
    //in this case
};

int main() {
	class Solution sn;
	return 0;
}

