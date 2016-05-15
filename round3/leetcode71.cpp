
class Solution {
public:
    //"/a/./b/../../c/"
    //"/a/b/../../c/"
    string simplifyPath(string path) {
        if (path.empty())
            return path;
        stack<string> st;
        int i = 0;
        int j = 0;
        //pre-process
        while (path.length() > 1 && path.back() == '/')
            path.pop_back();
        cout << path << endl;
        for (; i < path.length(); i ++) {
            if (i+1 == path.length()) {
                string curr = path.substr(j, path.length()-j);
                if (curr == "/..") {
                    if (!st.empty())
                        st.pop();
                }
                else if (curr == "/.")
                    st.push("/");
                else
                    st.push(curr);
                break;
            }
            if (path[i] == '/') {
                if (i == j)
                    continue;
                else {
                    string curr = path.substr(j, i-j);
                    j = i;
                    if (curr == "/..") {
                        if (!st.empty())
                            st.pop();
                    }
                    else if (curr == "/" || curr == "/.")
                        continue;
                    else
                        st.push(curr);
                }
            }
        }
        
        vector<string> tmp;
        while (!st.empty()) {
            tmp.push_back(st.top());
            st.pop();
        }
        reverse(tmp.begin(), tmp.end());
        string res;
        for (auto x : tmp)
            res += x;
        if (res.length() > 1 && res.back() == '/')
            res.pop_back();
        if (res.empty())
            res = "/";
        return res;
    }
};
