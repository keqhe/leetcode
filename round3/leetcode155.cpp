
class MinStack {
public:
    stack<pair<int,int>> st;//the first the real value, the second is the min
    void push(int x) {
        if (st.empty())
            st.push(make_pair(x,x));
        else {
            pair<int, int> t = st.top();
            if (x < t.second)
                st.push(make_pair(x,x));
            else
                st.push(make_pair(x,t.second));
        }
    }

    void pop() {
        if (!st.empty())
            st.pop();
    }

    int top() {
        if (!st.empty())
            return st.top().first;
    }

    int getMin() {
        if (!st.empty())
            return st.top().second;
    }
};
