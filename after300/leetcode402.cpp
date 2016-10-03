class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        if (num.length() <= k)
            return "0";
        for (int i = 0; i < num.length(); i ++) {
            //while (!st.empty() && st.top() >= num[i] does not work
            while (!st.empty() && st.top() > num[i] && 
            (st.size()-1+num.length()-i) >= (num.length()-k)) {
                st.pop();
            }
            st.push(num[i]);
        }
        string res;

        while (st.size() > num.length() - k) {
            st.pop();
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        while (res.length() > 1 && res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
