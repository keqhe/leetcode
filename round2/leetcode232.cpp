
class Queue {
public:
    stack<int> st1;//stack order
    stack<int> st2;//queue order
    // Push element x to the back of queue.
    //push(1), push(2), push(3)
    void push(int x) {
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        st1.push(x);
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (!st2.empty())
            st2.pop();
    }

    // Get the front element.
    int peek(void) {
        return st2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st2.empty();
    }
};
