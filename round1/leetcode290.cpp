
class Solution {
public:
    //"a" "dog" - true
    //"a" "dog " - true
    //""  "" - true
    //"ab" "dog cat"
    //"aba" "dog cat dog" - true
    //"aba" "dog cat dog " - false
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_map<string, char> map2;
        int i = 0;
        int prev_j = -1;
        for (i = 0; i < pattern.length(); i ++) {
            int j;
            char c = pattern[i];
            string sub;
            for(j = prev_j + 1; j < str.length(); j ++) {
                if (str[j] == ' ') {//
                    sub = str.substr(prev_j+1, j - (prev_j+1));
                    prev_j = j;
                    break;
                }
            }
            if (j == str.length())//last one, Made a MISTAKE here, thought it was j == str.length() - 1 LOL
                sub = str.substr(prev_j + 1, str.length() - (prev_j + 1));
            
            if (map.find(c) == map.end())//not inserted yet
                map[c] = sub;
            else {
                if (map[c] != sub)
                    return false;
            }
            
            //another direction
            if (map2.find(sub) == map2.end())
                map2[sub] = c;
            else {
                if (map2[sub] != c)
                    return false;
            }
        }
        
        //another case, "aaa" <---> "aa aa aa aa"
        string test;
        for (int i = 0; i < pattern.length(); i ++) {
            if (i < pattern.length() - 1)
                test += map[pattern[i]] + ' ';
            else 
                test += map[pattern[i]];
        }
        if (test != str)
            return false;
        return true;
    }
};
