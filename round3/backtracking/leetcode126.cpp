
class Solution {
public:
 
    vector<string> getNeighbors(string s, unordered_set<string> & wordList) {
        vector<string> res;
        for (int i = 0; i < s.length(); i ++) {
            for (char c = 'a'; c <= 'z'; c ++) {
                if (s[i] != c) {
                    char tmp = s[i];
                    s[i] = c;
                    if (wordList.find(s) != wordList.end())
                        res.push_back(s);
                    s[i] = tmp;
                }
            }
        }
        return res;
    }
    //dfs to get paths
    void dfs_old(string curr, string end, unordered_map<string, list<string>>&nei, unordered_map<string, int> & level, vector<string>&path, vector<vector<string>> & res) {
        path.push_back(curr);
        cout << curr << endl;
        if (curr == "hog") {
            list<string> tmp = nei[curr];
            for (auto x : tmp) {
                cout << "X:" << x << ' ';
            }
            cout << endl;
        }
        if (curr == end) {
            res.push_back(path);
            //return;
        }
        else {
            list<string> tmp = nei[curr];
            for (auto x : tmp) {
                if (level[x] == level[curr] + 1) {
                    dfs_old(x, end, nei, level, path, res);
                }
            }
        }
        path.pop_back();
        
    }
   
    vector<vector<string>> findLadders_old(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> res;
        wordList.insert(endWord);
        unordered_map<string, int> level;//BFS level, also used as "visited"
        unordered_map<string, list<string>> nei;//the neighbors of each string in the search path
        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 1;
        
        
        vector<string> test = getNeighbors("hot", wordList);
        for (auto x : test)
            cout << x << " ";
        cout << endl;
        bool found = false;
        while (!q.empty()) {
            int count = q.size();
            for (int k = 0; k < count; k ++) {
                string curr = q.front();
                int curr_level = level[curr];
                q.pop();
                vector<string> neighbors = getNeighbors(curr, wordList);
            
                //process 1 level
                for (int i = 0; i < neighbors.size(); i ++) {
                    string tmp = neighbors[i];
                    nei[curr].push_back(tmp);
                   
                    if (level.find(tmp) == level.end()) {//not visited
                        level[tmp] = curr_level+1;
                        if (endWord == tmp) {
                            found = true;
                        }
                        else 
                            q.push(tmp);
                    }
                }
            }
            if (found)
                break;//all shortest paths should be processed
        }
        
        vector<string> path;
        if (found) {
            dfs_old(beginWord, endWord, nei, level, path, res);
        }
        return res;
    }

    ///////////////////try again//////////////////
    
    void dfs2(unordered_map<string, vector<string>> &neighbors, unordered_map<string, int> level,
            string curr, string endWord, vector<string> & path, vector<vector<string>> & res) {
                if (curr == endWord) {
                    res.push_back(path);
                    return;
                }
                for (auto s : neighbors[curr]) {
                    if (level[s] == level[curr] + 1) {//this is important
                        path.push_back(s);
                        dfs2(neighbors, level, s, endWord, path, res);
                        path.pop_back();
                    }
                }
            }
    void dfs3(string curr, string end, unordered_map<string, vector<string>>&nei, unordered_map<string, int> & level, vector<string>&path, vector<vector<string>> & res) {
        path.push_back(curr);
        if (curr == end) {
            res.push_back(path);
        }
        else {
            vector<string> tmp = nei[curr];
            for (auto x : tmp) {
                if (level[x] == level[curr] + 1) {
                    dfs3(x, end, nei, level, path, res);
                }
            }
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> res;
        if (wordList.empty())
            return res;
        if (beginWord == endWord) {
            vector<string> tmp;
            tmp.push_back(beginWord);
            tmp.push_back(endWord);
            res.push_back(tmp);
            return res;
        }
        wordList.insert(endWord);
        unordered_map<string, int> level;
        unordered_map<string, vector<string>> neighbors;
        
        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 1;
        bool found = false;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                string curr = q.front();
                q.pop();
                int curr_level = level[curr];
                for (int j = 0; j < curr.length(); j ++) {
                    for (char c = 'a'; c <= 'z'; c ++) {
                        if (c != curr[j]) {
                            string tmp = curr;
                            tmp[j] = c;
                            if (wordList.find(tmp) != wordList.end()) {
                                neighbors[curr].push_back(tmp);
                                if (level.find(tmp) == level.end()) {
                                    level[tmp] = curr_level+1;
                                    if (tmp == endWord) {
                                        found = true;
                                    }
                                    else 
                                        q.push(tmp);
                                }
                            }
                        }
                    }
                }
                if (found)
                    break;//already found >= 1 word ladder
            }
        }//while
        if (found) {
            vector<string> path;
            //if use dfs2, i do not understand why my TLE, while dfs3 can pass, fuck
            //path.push_back(beginWord);//this is WRONG
            /*dfs2(neighbors, level, beginWord, endWord, path, res);
            for (auto & e : res) {
                e.insert(e.begin(), beginWord);
            }*/
            dfs3(beginWord, endWord, neighbors, level, path, res);
            return res;
        }
        else 
            return res;//no solution
    }
    
};
