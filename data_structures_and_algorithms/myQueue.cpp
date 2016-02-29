#include<string>
#include<list>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

/*topics: list, string, queue, stack, recursion
*/



int main() {
    queue<int> q;
    for (int i  = 1; i <= 5; i ++)
        q.push(i);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    if (!q.empty())
        q.front();
    return 0;
}



