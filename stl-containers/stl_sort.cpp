#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<queue>

using namespace std;

struct Node {
	int x;
	int y;
	Node (int x, int y) {
		this->x = x;
		this->y = y;
	}
};

bool mycmp(const struct Node *n1, const struct Node *n2) {
	return n1->x < n2->x;
}

class nodeCmp {
public:
	bool operator() (struct Node *n1, struct Node *n2) {
		return n1->x < n2->x;
	}
};

void printNodeVector(vector<struct Node*> & v) {
	for (auto & t : v) {
		cout << "(" << t->x << "," << t->y << ")," << " ";
	}
	cout << endl;
}

void printNodeList(list<struct Node*> & l) {
	for (auto & t : l) {
		cout << "(" << t->x << "," << t->y << ")," << " ";
	}
	cout << endl;
}
int main() {
	struct Node *n3 = new Node(3, 0);
	struct Node *n1 = new Node(1, 1);
	struct Node *n2 = new Node(2, 1);
	//sort apply to vector
	vector<struct Node*> v;
	v.push_back(n3);
	v.push_back(n1);
	v.push_back(n2);
	sort(v.begin(), v.end(), mycmp);
	//sort(v.begin(), v.end(), nodeCmp);
	printNodeVector(v);

	//sort apply to list
	list<struct Node*> lst;
	lst.push_back(n3);
	lst.push_back(n1);
	lst.push_back(n2);
	//sort(lst.begin(), lst.end(), mycmp);//WRONG for list
	lst.sort(mycmp);
	printNodeList(lst);

	//if we want to built priority queues, note that c++'s default is max heap
	//max heap uses std::less<int> for int, std::greater<int> is for min heap
	priority_queue<struct Node*, vector<struct Node*>, nodeCmp> q;//we want to get max heap
	//priority_queue<struct Node*, vector<struct Node*>, mycmp> q; //WRONG
	q.push(n3);
	q.push(n1);
	q.push(n2);
	while (!q.empty()) {
		struct Node * p = q.top();
		q.pop();
		cout << "(" << p->x << "," << p->y << ")," << " ";
	}
	cout << endl;
	return 0;	
	 
}
