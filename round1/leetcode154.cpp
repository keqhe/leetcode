
class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    int min;
    
    void push(int x) {
        st.push(x);
        if(min_st.empty()) {
            min_st.push(x);
            min = x;
        }
        else {
            if (x <= min) {
                min = x;
                min_st.push(x);
            }
        }
    }

    void pop() {
        if (st.top() == min_st.top()) {
                min_st.pop();
                if (!min_st.empty())
                        min = min_st.top();
        }
        if (!st.empty()) {
            st.pop();
        }
    }

    int top() {
        if (! st.empty())
            return st.top();
    }

    int getMin() {
        if (!min_st.empty())
           return min_st.top();
    }
};
