
class Solution {
public:
    //fb, remember? f*ck stupid waterloo!
    //first, BFS, see: https://leetcode.com/discuss/67842/share-my-java-bfs-solution
    bool isValid(string &s) {
        int cnt = 0;
        for (auto &x : s) {
            if (x == '(')
                cnt ++;
            else if (x == ')') {
                if (cnt == 0)
                    return false;
                cnt --;
            }
        }
        return cnt == 0;
    }
    vector<string> bfs_removeInvalidParentheses(string s) {
        vector<string> res;
        if (s.empty()) {
            res.push_back("");
            return res;
        }
        queue<string> q;
        unordered_set<string> se;//filter out duplicated strings
        bool found = false;
        q.push(s);
        while (!q.empty()) {
            string tmp = q.front();
            q.pop();
            
            if (isValid(tmp)) {//valid found
                res.push_back(tmp);
                found = true;
            }
            
            if (found)
                continue;//now need to delete more, haha
            for (int i = 0; i < tmp.size(); i ++) {
                if (tmp[i] == '(' || tmp[i] == ')') {
                    string a = "";
                    string b = "";
                    if (i > 0)
                        a =  tmp.substr(0, i);
                    if (i + 1 <= tmp.size()-1)
                        b = tmp.substr(i+1); //to the end;
                    string t = a + b;
                    if (se.find(t) == se.end()) {
                        q.push(t);
                        se.insert(t);
                    }
                }
            }
        }
        return res;
    }
    
    //another method, dfs, see: https://leetcode.com/discuss/67853/my-c-dfs-solution-16ms
    //http://www.hrwhisper.me/leetcode-remove-invalid-parentheses/
    void dfs(string s, int index, int left_removed, int right_removed, int pair, string path, unordered_set<string> & se) {
        if (index > s.size() || left_removed < 0 || right_removed < 0 || pair < 0)
            return;
        if (index == s.size() && left_removed == 0 && right_removed == 0 && pair == 0) {
            se.insert(path);
            return;
        }
        
        if (s[index] != '(' && s[index] != ')')
            dfs(s, index+1, left_removed, right_removed, pair, path+s[index], se);
        else {
            if (s[index] == '(') {
                dfs(s, index+1, left_removed-1, right_removed, pair, path, se);//not pick up
                dfs(s, index+1, left_removed, right_removed, pair+1, path+s[index], se);//pick up
            }
            else if (s[index] == ')') {
                dfs(s, index+1, left_removed, right_removed-1, pair, path, se);//not pick up
                dfs(s, index+1, left_removed, right_removed, pair-1, path+s[index], se);//pick it up
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        if (s.empty()) {
            res.push_back("");
            return res;
        }
        unordered_set<string> se;
        int left_removed = 0;
        int right_removed = 0;
        for (auto &x : s) {
            if (x == '(')
                left_removed ++;
            else if (x == ')') {
                if (left_removed == 0)
                    right_removed ++;
                else
                    left_removed --;
            }
        }
        dfs(s, 0, left_removed, right_removed, 0, "", se);
        
        for (auto &x : se) {
            res.push_back(x);
        }
        return res;
    }
};
