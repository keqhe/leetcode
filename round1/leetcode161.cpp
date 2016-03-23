
class Solution {
public:
    //ref:https://leetcode.com/discuss/71071/my-clear-java-solution-with-explanation
    //what is one edit?
    //add 1 char, delete 1 char or replace a char
    bool isOneEditDistance(string s, string t) {
        for (int i = 0; i < min(s.length(), t.length()); i ++) {
            cout << "debug.." << endl;
            if (s[i] != t[i]) {
                if (s.length() == t.length()) //replace one char in s to become t
                    return s.substr(i+1) == t.substr(i+1);
                else if (s.length() < t.length()) //delete one char from t
                    return s.substr(i) == t.substr(i+1);
                else //delete one char from s
                    return s.substr(i+1) == t.substr(i);
            }
        }
        //cout << abs((int)s.length() - (int)t.length()) << endl;
        //all are the same
        //return abs(s.length() - t.length()) == 1;//apply abs to unsigned int is WRONG!!!!
        return abs((int)s.length() - (int)t.length()) == 1;
    }
};
