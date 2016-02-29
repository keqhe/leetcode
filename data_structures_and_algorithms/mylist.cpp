//============================================================================
// Name        : mylist.cpp
// Author      : Keqiang He
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<string>
#include<list>
#include<iostream>
/*topics: list, string, queue, stack, recursion
*/
using namespace std;
int main() {
    list<int> l;
    for (int i = 1; i <= 5; i ++) {
        l.push_back(i);
    }
    //iterate thought the list from front to back
    for (auto x : l)
    	cout << x << " ";
    cout << endl;
    //iterate over the list, method 1, from front to back
    for (list<int>::iterator it = l.begin(); it != l.end(); it ++) {
    	cout << *it << " ";
    }
    cout << endl;

    cout << l.front() << endl;//it should output 1
    cout << l.back() << endl;

    //from back to front
    for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); it ++) {
        cout << *it << " ";
    }
    cout << endl;

    //how to insert elements into the list
    l.push_back(6);
    l.pop_back();

    //compared with vector, list has push_front and pop_front
    l.push_front(0);
    l.pop_front();

    //generalied, how to insert a value into the list
    //l.insert(l.begin()+1, 100);//pay attention to the difference from vector, for vectors, you can use v.insert(v.begin()+1, 100);
    l.insert(next(l.begin(),2), 100);
    for (auto x : l)
    	cout << x << " ";
    cout << endl;
    //if i want to delete the first element of the list
    l.erase(l.begin());
    //l.erase(l.begin()+1);
    l.erase(next(l.begin(),1));
    for (auto x : l)
    	cout << x << " ";
    cout << endl;

    l.insert(next(l.begin(),1),100);
    //sort
    l.sort();
    for (auto x : l)
    	cout << x << " ";
    cout << endl;

    //reverse
    l.reverse();
    for (auto x : l)
    	cout << x << " ";
    cout << endl;

    //splice
    list<int> q;
    for (int i=0; i<4; i++){
    	q.push_back(i+20);
    }

    //how to insert q[2,4) into the second position of l
    l.splice(next(l.begin(),1), q, next(q.begin(),1), next(q.begin(),3));
    for (auto x : l)
    	cout << x << " ";
    cout << endl;
    //in default, you can assume that for vector, list, queue,
    //stack, set, ...., they all have .empty() and .size()
    return 0;
}


