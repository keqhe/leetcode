
class MinStack {
public:
    stack<pair<int, int>> st;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (st.empty()) {
            st.push(make_pair(x, x));
        }
        else {
            if (x <= st.top().second) {
                st.push(make_pair(x, x));
            }
            else {
                st.push(make_pair(x, st.top().second));
            }
        }
    }
    
    void pop() {
        if (!st.empty())
            st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
