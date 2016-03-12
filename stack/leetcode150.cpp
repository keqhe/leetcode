#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto x : tokens) {
            if (x == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a+b);
            }
            else if (x == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b-a);
            }
            else if (x == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a*b);
            }
            else if (x == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b/a);
            }
            else {
                st.push(stoi(x));
            }
        }
        if (!st.empty()) {
            return st.top();
        }
        else
            return 0;
    }
};


