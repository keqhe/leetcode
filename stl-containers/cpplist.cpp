/*list is implemented in doubly-linked list*/
#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<vector>

using namespace std;

void printList(list<int> & l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it <<  ' ';
	}
	cout << endl;
}

void printListPair(list<pair<int, char>> & l) {
	for (list<pair<int,char>>::iterator it = l.begin(); it != l.end(); it ++) {
		cout << "(" << it->first << "," << it->second << ")" << ' ';
	}
	cout << endl;
}

struct Node {
	int x;
	int y;
	Node (int x, int y) {
		this->x = x;
		this->y = y;
	}
};

bool NodeCmp (const struct Node n1, const struct Node n2) {
	return n1.x < n2.x;
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

	cout << "insert 40 at list.begin() and 30 at list.end()" << endl;
	l.insert(l.begin(),40);//40 20 0 0 0 10
	l.insert(l.end(), 30);//40 20 0 0 0 10 30
	//l.insert(l.begin()+1, 35); //This is wrong, difference from vector
	printList(l);

	cout << "erase list.begin()" << endl;	
	l.erase(l.begin());
	list<int>::iterator it = l.begin();
	it ++;
	//l.erase(it+1); This is wrong
	//l.erase(l.begin()+1); //This is wrong, different from vector
	printList(l);

	cout << "erase next(list.begin(), 1)" << endl;
	l.erase(next(l.begin(),1));
	printList(l);

	cout << "list splice operations tests" << endl;
	list<pair<int, char>> l1, l2;
	for (int i = 0; i < 5; i ++) {
		std::pair<int,char> tmp(i, 'a' + i);
		l1.push_back(tmp);
	}
	for (int i = 0; i < 3; i ++) {
		l2.push_back(make_pair(10, 'a'+i));
	}

	cout << "list l1 is : " << endl;
	printListPair(l1);
	cout << "list l2 is : " << endl;
        printListPair(l2);

	cout << endl;
	list<pair<int,char>>::iterator lp = l1.begin();
	advance(lp, 1);//now lp points to (1, 'b');
	l1.splice(lp, l2, l2.begin());
	cout << "move l2's first element to l1's second position" << endl;
	cout << "now l1 is : " << endl;
	printListPair(l1);
	cout << "now l2 is : " << endl;
	printListPair(l2);

	cout << "\ncall list.size() to get the size of each list" << endl;
	cout << "l1 size is " << l1.size() << endl;
	cout << "l2 size is " << l2.size() << endl;

	cout << "\n list.splice can also work on the same list.." << endl;
	cout << "mov the third element of l1 to its begining" << endl;
	l1.splice(l1.begin(), l1, next(l1.begin(),2));
	cout << "now l1 becomes : " << endl;
	printListPair(l1);


	cout << "a common error is about list.begin() vs list.front() and list.end() vs list.back()" << endl;
	//check sort
	l.clear();
	printList(l);
	l.push_back(2);
	l.push_back(1);
	l.push_back(3);
	printList(l);	
	//sort(l.begin(), l.end());//sort can not be applied to C++ list like this
	l.sort(std::greater<int>());
	printList(l);
	//what about sorting struct?
	list<struct Node> l3;
	struct Node n1(2, 2);
	struct Node n2(1, 1);
	l3.push_back(n1);
	l3.push_back(n2);
	l3.sort(NodeCmp);
	for (list<struct Node>::iterator it = l3.begin(); it != l3.end(); it ++) {
		cout << "(" << it->x << "," << it->y << ")" << " ";
	}
	cout << endl;
	//more about erase
	list<int> l4;
	for (int i = 0; i < 10; i ++)
		l4.push_back(i);
	printList(l4);
	list<int>::iterator it4 = l4.begin();
	/*below is wrong
	for (list<int>::iterator it = l4.begin(); it != l4.end(); it ++) {
		l4.erase(it);
	}*/
	while (it4 != l4.end()) {
		it4 = l4.erase(it4); //or l4.erase(it4++)
	}
	printList(l4);
	//list insert a range of elements
	vector<int> test1 = {1, 2, 3, 4, 5};
	vector<int> test2 = {11, 12, 13, 14, 15};
	list<vector<int>::iterator> l5;
	for (vector<int>::iterator it = test1.begin(); it != test1.end(); it ++)
		l5.push_back(it);
	for (vector<int>::iterator it = test2.begin(); it != test2.end(); it ++)
                l5.push_back(it);	
	for (auto & x : l5)
		cout << *x << " ";
	cout << endl;
	return 0;
}

/*i guess that is because vector gets continuous memory while list does not*/
//notice the difference between advance(it, 1) and next(it, 1); former modifies it and the second keeps it the same but return the proper interator
