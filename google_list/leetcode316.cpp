
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.length() < 2)
            return s;
        unordered_map<char, int> m;
        unordered_set<char> used;
        for (auto c : s) {
            m[c] ++;
        }
        stack<char> st;
        for (auto c : s) {
            if (used.find(c) == used.end()) {
                while (!st.empty() && st.top() > c && m[st.top()] > 0) {
                    //m[st.top()] --; //otherwise, minus twice
                    used.erase(used.find(st.top()));
                    st.pop();
                }
                st.push(c);
                used.insert(c);
            }
            m[c] --;
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
