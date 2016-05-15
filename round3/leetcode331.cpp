
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty())   
            return false;
        stack<string> st;
        int i = 0;
        vector<string> tmp;
        while (i < preorder.length()) {
            size_t pos = preorder.find(',', i);
            if (pos == string::npos) {
                tmp.push_back(preorder.substr(i, preorder.length()-i));
                break;
            }
            else {
                tmp.push_back(preorder.substr(i, pos-i));
                i = pos + 1;
            }
        }
        for (auto x : tmp) {
            if (x == "#") {
                while (!st.empty() && st.top() == "#") {
                    st.pop();
                    if (st.empty())
                        return false;
                    st.pop();
                }
            }
            st.push(x);
        }
        return st.size()==1 && st.top() == "#";
    }
};
