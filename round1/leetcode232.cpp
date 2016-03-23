
class Queue {
public:
    stack<int> st;
    // Push element x to the back of queue.
    void push(int x) {
        st.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> temp;
        while (!st.empty()) {
            int t = st.top();
            temp.push(t);
            st.pop();
        }
        if (!temp.empty())
            temp.pop();
        while(!temp.empty()) {
            int t = temp.top();
            st.push(t);
            temp.pop();
        }
            
    }

    // Get the front element.
    int peek(void) {
        stack<int> temp;
        int ret;
        while (!st.empty()) {
            int t = st.top();
            temp.push(t);
            st.pop();
        }
        ret = temp.top();
        while(!temp.empty()) {
            int t = temp.top();
            st.push(t);
            temp.pop();
        }
        return ret;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st.empty();
    }
};
