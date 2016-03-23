
struct wordNode {
        string w;
        int steps;
        struct wordNode * prev = NULL;
        wordNode (string val, int st, struct wordNode * p) {
            w = val;
            steps = st;
            prev = p;
        }
};
    
class Solution {
public:
    //ref1: word ladder1, http://www.programcreek.com/2012/12/leetcode-word-ladder/
    //ref2: word ladder2, http://www.programcreek.com/2014/06/leetcode-word-ladder-ii-java/

    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        queue<struct wordNode *> q;
        q.push(new wordNode(beginWord, 1, NULL));
        
        vector<vector<string>> res;
        wordList.insert(endWord);
        
        int minStep = 0;
        int prevStep = 0;
        int currStep = 0;
        
        unordered_set<string> visited;
        unordered_set<string> unvisited;
        
        for (auto & x : wordList)
            unvisited.insert(x);
            
        while (!q.empty()) {
            struct wordNode * curr = q.front();
            q.pop();
            currStep = curr->steps;
            if (curr->w == endWord) {//solutions found
                if (minStep == 0) {//first time to find a feasible solution
                    minStep = currStep;
                }
                
                if (minStep == currStep && minStep != 0) {//solutions found 
                    vector<string> temp;
                    while (curr != NULL) {
                        temp.push_back(curr->w);
                        curr = curr->prev;
                    }
                    reverse(temp.begin(), temp.end());
                    res.push_back(temp);
                    continue;//ciritical to find all possible solutions
                }
            }
            
            if (prevStep < currStep) {//if prev and curr at the same "level", no need to erase the elements put into queue in the prev step
                for (auto x : visited)
                    unvisited.erase(x);
            }
            
            prevStep = currStep;
            
            string currStr = curr->w;
            for (int i = 0; i < currStr.length(); i ++) {
                char temp = currStr[i];
                for (char j = 'a'; j <= 'z'; j ++) {
                    if (j != temp) {
                        currStr[i] = j;
                        
                        if (unvisited.find(currStr) != unvisited.end()) {//not visited
                            q.push(new wordNode(currStr, currStep+1, curr));
                            visited.insert(currStr);
                        }
                    }
                }
                currStr[i] = temp;
            }
        }
        
        return res;
    }
};
