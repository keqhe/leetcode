#include<iostream>
#include<string>
#include<stack>

using namespace std;

class MinStack {
public:
    stack<pair<int, int>> st;
    void push(int x) {
        if (st.empty()) {
            st.push(make_pair(x,x));
        }
        else {
            pair<int, int> a = st.top();
            if (x < a.second) {
                st.push(make_pair(x,x));
            }
            else
                st.push(make_pair(x,a.second));
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        if (!st.empty()) {
            pair<int, int> a = st.top();
            return a.first;
        }
    }

    int getMin() {
        if (!st.empty()) {
            pair<int, int> a = st.top();
            return a.second;
        }
    }
};

int main() {
	class MinStack sn;
	return 0;
}

