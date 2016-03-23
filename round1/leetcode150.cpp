
class Solution {
public:
    //note switch (Int), switch (string) does not work!!!
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty())
            return 0;
        stack<int> st;
     
        unordered_map<string, int> m;
        m["+"] = 1;
        m["-"] = 2;
        m["*"] = 3;
        m["/"] = 4;
        for (int i = 0; i < tokens.size(); i ++) {
            string str = tokens[i];
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                switch (m[str]) {
                case 1: {
                    int a = st.top(); 
                    st.pop();
                    int b = st.top();
                    st.pop();
                    int c = a + b;
                    st.push(c);
                    break;
                }
                case 2: {
                    int a = st.top(); 
                    st.pop();
                    int b = st.top();
                    st.pop();
                    int c = b - a;
                    st.push(c);
                    break;
                }
                case 3: {
                    int a = st.top(); 
                    st.pop();
                    int b = st.top();
                    st.pop();
                    int c = a * b;
                    st.push(c);
                    break;
                }
                case 4: {
                    int a = st.top(); 
                    st.pop();
                    int b = st.top();
                    st.pop();
                    int c = b/a;
                    st.push(c);
                    break;
                }
                }
            }
            else {
                    int a = stoi(str);
                    st.push(a);
            }
        }
        return st.top();
    }
};
