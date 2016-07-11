
class Solution {
public:
    //the difficulty of this problem is that they are so many corner cases
    bool isValidSerialization(string preorder) {
        stack<string> st;
        int i = 0;
        while (i < preorder.length()) {
            // need to remeber the following function, find for string, the first parameter is the char or string pattern we want to find the second parameter is the starting index (inclusive)
            std::size_t pos = preorder.find(',', i);
            string curr;
            if (pos == string::npos) {
                curr = preorder.substr(i);
            }
            else
                curr = preorder.substr(i, pos-i);
            cout << pos << " " << i << " " << curr << endl;
            st.push(curr);
            while (!st.empty() && st.top() == "#") {
                st.pop();
                if (!st.empty() && st.top() == "#") {
                    st.pop();
                    if (!st.empty()) {
                        st.pop();
                        st.push("#");
                    }
                    else {
                        cout << "debug: " << curr << endl;
                        return false;
                    }
                }
                else {
                    st.push("#");
                    break;
                }
            }
            if (pos == string::npos)
                break;
            i = pos+1;
        }
        cout << st.empty();
        return st.size() == 1 && st.top() == "#";//[1, #]
    }
};
