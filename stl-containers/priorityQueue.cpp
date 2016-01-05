#include<iostream>
#include<string>
#include<queue> //std::priority_queue

using namespace std;

//priority queue in C++ is head (max head in default)
//push, pop, top, but no erase. O(logN)
struct Node {
	int x;
	int y;
	Node() {}
	Node(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

//note this is like std::greater<int>, so it is a min heap
class myCmp {
public:
	bool operator() (const struct Node n1, const struct Node n2) {
		if (n1.x != n2.x) 
			return n1.x > n2.x;
		else
			return n1.y > n2.y;
	}
};


int main() {
	priority_queue<int, vector<int>> pq1; //max head, std::less<int>
	pq1.push(10);
	pq1.push(50);
	pq1.push(60);
	pq1.push(20);

	while (!pq1.empty()) {
		cout << pq1.top() << ' ';
		pq1.pop();
	}
	cout << endl;
	//
	
	priority_queue<int, vector<int>, std::greater<int>> pq2;//min heap
        pq2.push(10);
        pq2.push(50);
        pq2.push(60);
        pq2.push(20);
	pq2.push(20);
        while (!pq2.empty()) {
                cout << pq2.top() << ' ';
                pq2.pop();
        }
        cout << endl;

	struct Node n1(1, 100);
	struct Node n2(2, 500);
	struct Node n3(2, 200);
	struct Node n4(0, 10);

	std::priority_queue<struct Node, vector<struct Node>, myCmp> pq3;
	pq3.push(n1);
	pq3.push(n2);
	pq3.push(n3);
	pq3.push(n4);
	while (!pq3.empty()) {
		struct Node tmp = pq3.top();
		pq3.pop();
		cout << tmp.x << ' ' << tmp.y << endl;
	}

	cout << pq3.size() << endl;
	return 0;
}
