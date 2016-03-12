#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    //ref: https://leetcode.com/discuss/86379/share-my-stack-based-java-code-with-comments
    //https://leetcode.com/discuss/83225/clean-easy-understand-java-stack-solution-with-explanation
    string removeDuplicateLetters(string s) {
        vector<int> count (26, 0);
        vector<bool> used (26, false);
        stack<char> st;
        for (auto c : s) {
            count[c-'a'] ++;
        }
        cout << "debug1" << endl;
        for (auto c : s) {
            if (!used[c-'a']) {
                while (!st.empty() && st.top() > c && count[st.top()-'a'] >= 1) {
                    used[st.top()-'a'] = false;
                    st.pop();
                }
                st.push(c);
                used[c-'a'] = true;
            }
            count[c-'a'] --;
        }
        cout << "debug2" << endl;
        string res;
        while(!st.empty()) {
            char c = st.top();
            st.pop();
            res.push_back(c);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
