
class Solution {
public:
    //ref: https://leetcode.com/discuss/64522/simple-backtracking-inspired-by-flip-game-i
    //using hash map to improve, see, https://leetcode.com/discuss/64486/backtracking-solution-time-optimization-through-205ms-19ms
    bool helper(string &s, unordered_map<string, bool> & winmap) {
        if (winmap.find(s) != winmap.end()) {
            return winmap[s];
        }
        for (int i = 0; i < s.length() - 1; i ++) {
            if (s[i] == '+' && s[i+1] == '+') {
                string tmp = s.substr(0,i) + "--" + s.substr(i+2);
                if (!helper(tmp, winmap)) {
                    winmap[s] = true;
                    return true;
                }
            }
        }
        winmap[s] = false;
        return false;
    }
    bool canWin(string s) {
        if (s.length() <= 1)
            return false;
        unordered_map<string, bool> winmap;
        return helper(s, winmap);
    }
};
