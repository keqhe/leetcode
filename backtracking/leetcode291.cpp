#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool backtracking(string pattern, int i1, string str, int i2, unordered_map<char, string>&m1,
        unordered_map<string, char> & m2) {
            if (i1 == pattern.length() && i2 == str.length())
                return true;
            if (i1 >= pattern.length() || i2 >= str.length())
                return false;
                
            char c = pattern[i1];
            for (int l = 1; l+i2 <= str.length(); l ++) {
                string s = str.substr(i2, l);
                bool check = false;
                if (m1.find(c) == m1.end() && m2.find(s) == m2.end()) {
                    m1[c] = s;
                    m2[s] = c;
                    if (backtracking(pattern, i1+1, str, i2+l, m1, m2))
                        return true;
                    m1.erase(c);
                    m2.erase(s);
                }
                else if (m1.find(c) != m1.end() && m2.find(s) != m2.end()) {
                    if (m1[c] == s && m2[s] == c)
                        if (backtracking(pattern, i1+1, str, i2+l, m1, m2))
                            return true;
                }
            }
            
            return false;
        }
    bool wordPatternMatch(string pattern, string str) {
        /*if (pattern.empty() || str.empty())
            return false;
        *///in leetcode, we should return false for this case...
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        return backtracking(pattern, 0, str, 0, m1, m2);
    }
};

int main() {
	class Solution sn;
	return 0;
}
