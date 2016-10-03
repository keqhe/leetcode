
class Solution {
public:
    vector<string> split(string s, char x) {//"1,23,4"
        int i = 0;
        int prev = 0;
        vector<string> res;
        while (i < s.length()) {
            while (i < s.length() && s[i] != x)
                i ++;
            string curr = s.substr(prev, i-prev);
            i ++;
            prev = i;
            res.push_back(curr);
        }
        return res;
    }
    bool insert(stack<string> & st) {
        st.push("#");
        if (st.size() >= 3) {
            if (st.top() == "#") {
                st.pop();
                if (st.top() == "#") {
                    st.pop();
                    if (st.top() == "#")
                        return false;
                    st.pop();
                    insert(st);
                }
                else
                    st.push("#");
            }
        }
        return true;
    } 
    bool isValidSerialization(string preorder) {
        stack<string> st;
        vector<string> tokens = split(preorder, ',');
        
        for (auto x : tokens) {
            cout << x << " ";
            if (x == "#") {
                if (!insert(st))
                    return false;
            }
            else {
                st.push(x);
            }
        }
        cout << endl;
        cout << st.size() << " " << st.top() << endl;
        return st.size() == 1 && st.top() == "#";
    }
};
