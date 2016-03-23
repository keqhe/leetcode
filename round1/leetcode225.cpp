
class Stack {
public:
    queue<int> q;
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i ++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    void pop () {
        q.pop();
    }
    
    int top() {
        return q.front();
    }
    void push2(int x) {
        q.push(x);
    }
    //push(1), push(2), pop()
    // 1, 2
    //
    // Removes the element on top of the stack.
    void pop2() {
        int n = q.size();
        int * temp;
        int i = 0;
        if (n > 0) {
            temp = new int[n];//dynamically allocate an array
        }
        while(!q.empty()) {
            int t = q.front();
            temp[i] = t;
            i ++;
            q.pop();
        }
        for (int j = 0; j < i - 1; j ++) { //the last element, kick off
            q.push(temp[j]);
        }
        
        if(n > 0)
            delete [] temp;
    }

    // Get the top element.
    int top2() {
        //return q.back();//C++ queue has a member function "back", "front" == "top"
        int n = q.size();
        int * temp;
        int i = 0;
        int ret;
        if (n > 0) {
            temp = new int[n];//dynamically allocate an array
        }
        while(!q.empty()) {
            int t = q.front();
            temp[i] = t;
            i ++;
            q.pop();
        }
        
        if (i >= 1)
            ret = temp[i-1];
            
        for (int j = 0; j < i; j ++) { //the last element, NO kick off
            q.push(temp[j]);
        }
        
        if(n > 0)
            delete [] temp;
            
        return ret;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
