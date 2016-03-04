#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<list>

using namespace std;

class Solution {
public:
    //the hard part is how to trace the paths
    //ref:
    //https://leetcode.com/discuss/64808/my-concise-java-solution-based-on-bfs-and-dfs
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
    void dfs(string curr, string end, unordered_map<string, list<string>>&nei, unordered_map<string, int> & level, vector<string>&path, vector<vector<string>> & res) {
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
                    dfs(x, end, nei, level, path, res);
                }
            }
        }
        path.pop_back();
        
    }
    //i submitted this version many times, i just want to keep it to remind me where goes wrong
    /*
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
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
            found = false;
            string curr = q.front();//HERE GOES WRONG, think about level order travsal
            int curr_level = level[curr];
            q.pop();
            vector<string> neighbors = getNeighbors(curr, wordList);
            if (curr == "hog") {
                cout << "debug1" << endl;
                for (auto x : neighbors)
                    cout << x << " ";
                cout << endl;
            }
            //process 1 level
            for (int i = 0; i < neighbors.size(); i ++) {
                string tmp = neighbors[i];
                nei[curr].push_back(tmp);
                if (tmp == "hog")
                    cout << "debug2" << endl;
                if (level.find(tmp) == level.end()) {//not visited
                    if (tmp == "hog")
                        cout << "debug3" << endl;
                    level[tmp] = curr_level+1;
                    if (endWord == tmp) {
                        found = true;
                    }
                    else 
                        q.push(tmp);
                }
            }
            if (found)
                break;//all shortest paths should be processed
        }
        
        vector<string> path;
        if (found) {
            dfs(beginWord, endWord, nei, level, path, res);
        }
        return res;
    }
    */
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
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
            dfs(beginWord, endWord, nei, level, path, res);
        }
        return res;
    }
};

int main() {
	class Solution sn;
	return 0;
}
