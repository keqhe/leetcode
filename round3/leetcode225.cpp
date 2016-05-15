
class Stack {
public:
    queue<int> q;
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> tmp;
        while (q.size() > 1) {
            int a = q.front();
            q.pop();
            tmp.push(a);
        }
        if (!q.empty())
            q.pop();//last element
        while (!tmp.empty()) {
            q.push(tmp.front());
            tmp.pop();
        }
    }

    // Get the top element.
    int top() {
        queue<int> tmp;
        int res;
        while (!q.empty()) {
            int a = q.front();
            if (q.size() == 1)
                res = a;
            q.pop();
            tmp.push(a);
        }
        
        while (!tmp.empty()) {
            q.push(tmp.front());
            tmp.pop();
        }
        return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
