
class Queue {
public:
    stack<int> oldstack;
    stack<int> newstack;
    // Push element x to the back of queue.
    void push(int x) {
        newstack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (!oldstack.empty())
            oldstack.pop();
        else if (!newstack.empty()) {
            while (!newstack.empty()) {
                oldstack.push(newstack.top());
                newstack.pop();
            }
            oldstack.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if (!oldstack.empty())
            return oldstack.top();
        else if (!newstack.empty()) {
            while (!newstack.empty()) {
                oldstack.push(newstack.top());
                newstack.pop();
            }
            return oldstack.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return oldstack.empty() && newstack.empty();
    }
};
