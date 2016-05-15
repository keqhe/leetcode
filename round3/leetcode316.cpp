
class Solution {
public:
    //the idea is using stack, but the conditions need to be carefully thought
    string removeDuplicateLetters(string s) {
        if (s.length() < 2)
            return s;
        unordered_map<char, int> m;
        unordered_set<char> used;
        for (auto c : s)
            m[c] ++;
        stack<char> st;
        for (int i = 0; i < s.length(); i ++) {
            if (used.find(s[i]) == used.end()) {
                while (!st.empty() && s[i] < st.top() && m[st.top()] > 0) {
                    used.erase(st.top());
                    st.pop();
                }
                st.push(s[i]);
                used.insert(s[i]);
            }
            m[s[i]] --;
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
