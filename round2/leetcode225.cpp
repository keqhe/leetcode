
class Stack {
public:
    queue<int> q1;
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> tmp;
        while (q1.size() > 1) {
            tmp.push(q1.front());
            q1.pop();
        }
        if (!q1.empty())
            q1.pop();
        while (!tmp.empty()) {
            q1.push(tmp.front());
            tmp.pop();
        }
    }

    // Get the top element.
    int top() {
        queue<int> tmp;
        while (q1.size() > 1) {
            tmp.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        tmp.push(q1.front());
        q1.pop();
        while (!tmp.empty()) {
            q1.push(tmp.front());
            tmp.pop();
        }
        return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};
