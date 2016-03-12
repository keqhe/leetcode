#include<stack>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int start = -1;//the first non-
        for (int i = 0; i < path.length(); i ++) {
            if (path[i] == '/') {
                if (start == -1) {
                    start = i;
                    continue;
                }
                string str = path.substr(start+1, i-start-1);
                cout << "str is:" << str << endl;
                if (!str.empty()) {
                    if (str == "..") {
                        if (!st.empty())
                            st.pop();
                    } 
                    else if (str != ".")
                        st.push(str);
                }
                start = i;
            }
            else if (i == path.length()-1) {
                string str = path.substr(start+1, i-start);
                if (!str.empty()) {
                    if (str == "..") {
                            if (!st.empty())
                                st.pop();
                    } 
                    else if (str != ".")
                        st.push(str);
                }
            }
        }
        string res;
        cout << st.size() << endl;
        while(!st.empty()) {
            res = '/' + st.top() + res;
            st.pop();
        }
        if (res.empty())
            res = "/";
        return res;
    }
};


