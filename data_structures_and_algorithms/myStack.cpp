#include<string>
#include<list>
#include<iostream>
#include<stack>

using namespace std;

/*topics: list, string, queue, stack, recursion
*/



int main() {
    stack<int> st;
    
    for (int i = 1; i <= 5; i ++) {
        st.push(i);
    }
    
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    //mistakes  if we do not check whether st is empty or not
    if (!st.empty())
        st.top();
    return 0;
}



