
struct GraphNode {
        string key;
        int color; //0: white; 1: gray; 2: black
        int dist; // distance from the source
        GraphNode (string s) {
            key = s;
            color = 0;
            dist = numeric_limits<int>::max();
        }
};
    
class Solution {
public:
    //graph, BFS to get the shortest path
    //reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-word-ladder-i-ii.html
    
    
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        //wordList.insert(beginWord);
        wordList.insert(endWord);
        queue<pair<string, int>> q;
        
        unordered_map<string, int> color;
        
        for (auto x: wordList) {
            color[x] = 0;// 0 is white; 1 is gray and 2 is black
        }
        
        q.push(make_pair(beginWord, 1));
        color[beginWord] = 1;
        
        while (!q.empty()) {
           pair<string, int> tmp = q.front();
           q.pop();
           
           if (tmp.first == endWord)
                return tmp.second;
           vector<string> neighbors = findNeighbor(tmp.first, wordList, color);
           for (auto x : neighbors) 
               cout << x << ' ';
           cout << endl;
           for (auto x: neighbors) {//all white neighbors
               q.push(make_pair(x, tmp.second+1));
               color[x] = 1;
               
           }
           
           color[tmp.first] = 2;
        }
        
        return 0;
    }
    
    vector<string> findNeighbor(string s, unordered_set <string> & wordList, unordered_map<string, int> & color) {
        int len = s.length();
        
        vector<string> res;
        for (int i = 0; i < len; i ++) {
            string str = s;
            for (char c = 'a'; c <= 'z'; c ++) {
                if (c != s[i]) {
                    str[i] = c;
                    if (wordList.find(str) != wordList.end() && color[str] == 0)
                        res.push_back(str);
                }
            }
        }
        return res;
    }
};
