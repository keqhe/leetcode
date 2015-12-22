/*list is implemented in doubly-linked list*/
#include<iostream>
#include<string>
#include<list>

using namespace std;

void printList(list<int> & l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it <<  ' ';
	}
	cout << endl;
}
int main() {
	list<int> l (3);//3 zeros
	printList(l);
	l.push_back(10);// 0 0 0 10
	printList(l);
	
	l.push_front(20);//20 0 0 0 10
	printList(l);
	
	l.push_back(30);//20 0 0 0 10 30
	l.push_front(40);//40 20 0 0 0 10 30
	printList(l);
	
	l.pop_front();//20 0 0 0 10 30 
	l.pop_back();//20 0 0 0 10
	printList(l);

	l.insert(l.begin(),40);//40 20 0 0 0 10
	l.insert(l.end(), 30);//40 20 0 0 0 10 30
	//l.insert(l.begin()+1, 35); //This is wrong, difference from vector
	printList(l);
	
	l.erase(l.begin());
	list<int>::iterator it = l.begin();
	it ++;
	//l.erase(it+1); This is wrong
	//l.erase(l.begin()+1); //This is wrong, different from vector
	printList(l);
	return 0;
}

/*i guess that is because vector gets continuous memory while list does not*/
