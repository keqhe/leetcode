
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty())
            return "";
        stack<char> st;
        unordered_map<char, int> m;
        unordered_set<char> used;
        for (auto c : s) {
            m[c] ++;
        }
        int i = 0;
        while (i < s.length()) {
            if (used.find(s[i]) == used.end()) {
                while (!st.empty() && i < s.length() && st.top() > s[i] && m[st.top()] > 0) {
                    used.erase(st.top());
                    st.pop();
                }
                st.push(s[i]);
                used.insert(s[i]);
            }
            m[s[i]] --;
            i ++;
        }
        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
