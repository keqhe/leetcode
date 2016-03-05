#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    //ref1: https://leetcode.com/discuss/72208/easiest-9ms-java-solution
    //ref2: https://leetcode.com/discuss/68192/java-bfs-40ms-and-dfs-17ms-without-hashset
    
    //DFS first, because it is easier to understand
    //https://leetcode.com/discuss/72208/easiest-9ms-java-solution
    //i think it is backtracking
    void dfs(unordered_set<string> & se, string s, int index, int rmL, int rmR, int open, string path) {
        if (index == s.length() && rmL == 0 && rmR == 0 && open == 0) {
            se.insert(path);
            return;
        }
        if (index == s.length() || rmL < 0 || rmR < 0 || open < 0)//invalid
            return;
            
        if (s[index] == '(') {
            dfs(se, s, index+1, rmL-1, rmR, open, path);//do not take this "("
            dfs(se, s, index+1, rmL, rmR, open+1, path+s[index]);//take this '('
        }
        else if (s[index] == ')') {
            dfs(se, s, index+1, rmL, rmR-1, open, path);//do not take this ')'
            dfs(se, s, index+1, rmL, rmR, open-1, path+s[index]);//take this
        }
        else {
            dfs(se, s, index+1, rmL, rmR, open, path+s[index]);
        }
    }
    //the variable rmL and rmR and open are really nice to cut unnecessary branches
    //unordered_set are used to de-duplicate the results
    vector<string> removeInvalidParentheses_dfs(string s) {
        vector<string> res;
        if (s.empty()) {
            res.push_back("");
            return res;
        }
        int rmL = 0;//how many '(' shoud be removed in order to make it balance
        int rmR = 0;//how many ')' shoud be removed to make it balance
        
        for (auto c : s) {
            if (c == '(') rmL ++;
            else if (c == ')') {
                if (rmL > 0)
                    rmL --;
                else
                    rmR ++;
            }
        }
        cout << rmL << " " << rmR << endl;
        unordered_set<string> se;
        dfs(se, s, 0, rmL, rmR, 0, "");
        cout << se.size() << endl;
        for (auto x : se)
            res.push_back(x);
        return res;
    }
    
    //this BFS is easier to understand and coding
    //see ref: https://leetcode.com/discuss/68281/a-simple-c-bfs-solution
    //the idea is, for each '(' or ')', try to delete it see what will happen
    //because using BFS, it is guaranteed to generated longest valid results, no need to use rmL, rmR
    bool isValid(string s) {//using a counter to check whether a string is valid parathenses 
        int left = 0;
        for (auto c : s) {
            if (c == '(')
                left ++;
            else if (c == ')') {
                if (left > 0)
                    left --;
                else
                    return false;
            }
        }
        return left == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        if (s.empty()) {
            res.push_back("");
            return res;
        }
        queue<string> q;
        unordered_set<string> checked;
        unordered_set<string> se;
        
        q.push(s);
        bool found = false;
        while (!q.empty()) {
            int size = q.size();
        
            for (int k = 0; k < size; k ++) {
                string curr = q.front();
                q.pop();
                if (isValid(curr)) {
                    se.insert(curr);//de-deplicate
                    found = true;
                }
                int len = curr.length();
                for (int i = 0; i < len; i ++) {//try to erase every possible position..
                    if (curr[i] == '(' || curr[i] == ')') {
                        string to_add = curr.substr(0, i) + curr.substr(i+1);
                        if (checked.find(to_add) == checked.end()) {//to avoid unnecessary exploration
                            q.push(to_add);
                            checked.insert(to_add);
                        }
                    }
                }
            }
            if (found)
                break;//no need to erase more...
        }
        
        for (auto x : se)
            res.push_back(x);
        return res;
    }
};

int main() {
	class Solution sn;
	return 0;
}
