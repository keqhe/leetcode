#include<iostream>
#include<string>
#include<set>

using namespace std;
/*multiset is implemented in RB tree like data structure, so find, insert and earse is O(logN) */
/*allow duplicates*/

void printMultiSet(multiset<int> & ms) {
	for (auto x : ms) 
		cout << x << ' ';
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

class myCmp {
public:
	bool operator() (const struct Node n1, const struct Node n2) {
		if (n1.x != n2.x) 
			return n1.x < n2.x;
		else 
			return n1.y < n2.y;
	}
};

int main() {
	multiset<int> ms;
	ms.insert(40);
	for (int i = 0; i < 5; i ++) {
		ms.insert(i*10);
	}

	printMultiSet(ms);
	cout << "number of 40s is " << ms.count(40) << endl;
	ms.erase(40);
	printMultiSet(ms);
	cout << "number of 40s is " << ms.count(40) << endl;

	multiset<struct Node, myCmp> obj;
	struct Node n1(1, 100);
	struct Node n2(2, 200);
	struct Node n3(2, 100);
	struct Node n4(0, 500);
	obj.insert(n1);
	obj.insert(n2);
	obj.insert(n3);
	obj.insert(n4);

	for (multiset<struct Node, myCmp>::iterator it = obj.begin(); it != obj.end(); it ++) {
		cout << it->x << ' ' << it->y << ' ';
	}
	cout << endl;
	return 0;
}
