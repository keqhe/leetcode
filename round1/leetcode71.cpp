
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        if (path.empty())
            return "";
            
        while (path.length() > 0 && path.back() == '/')//e.g.,/////
            path.pop_back();
            
        path.push_back('/');
        int last_slash = 0;
        for (int i = 0; i < path.size(); i ++) {
            if (i > 0 && path[i] == '/' && path[i-1] == '/') {
                last_slash = i;
                continue;
            }
            if (i > 0 && path[i] == '/') {//e.g., /a/b
                string s = path.substr(last_slash, i - last_slash);
                last_slash = i;
                if (s == "/.") {
                    continue;
                }
                else if (s == "/..") {
                    if (!st.empty())
                        st.pop();
                }
                else 
                    st.push(s);
            }
        }
        
        string res;
        if (st.empty())
            res = "/";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};
