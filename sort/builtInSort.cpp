#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void printVector(vector<int> & nums) {
	for (int i = 0; i < nums.size(); i ++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
}

bool mycmp (const int x, const int y) { //const int or int is okay, int & is NOT okay
	return x < y;
}


struct Node {
	int x;
	int y;
	Node () {}
	Node (int x, int y) {
		this->x = x;
		this->y = y;
	}
};

bool cmpNode(const struct Node n1, const struct Node n2) {
	return n1.x < n2.x;
}

void printVectorNode(vector<struct Node> & nodes) {
	for (int i = 0; i < nodes.size(); i ++) {
		cout << "[" << nodes[i].x << "," << nodes[i].y << "]" << ' ';
	}
	cout << endl;
}
int main() {
	vector<int> a {1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> b = {9, 9, 7, 6, 6, 4, 3, 2};
	
	sort(a.begin(), a.end());
	printVector(a);

	sort(a.begin(), a.end(), std::greater<int>()); //default is std::less<int>()
	printVector(a);

	sort(a.begin(), a.end(), mycmp);
	printVector(a);

	stable_sort(b.begin(), b.end());
	printVector(b);


	vector<struct Node> nodes;
	struct Node n1 (2, 20);
	struct Node n2 (2, 2);
	struct Node n3 (2, 3);
	struct Node n4 (1, 10);
	struct Node n5 (1, 5);
	struct Node n6 (1, 7);
	struct Node n7 (1, 8);
	struct Node n8 (1, 9);
	struct Node n9 (1, 11);
	struct Node n10 (1, 12);
	struct Node n11 (1, 15);

	nodes.push_back(n1);
	nodes.push_back(n2);
	nodes.push_back(n3);
	nodes.push_back(n4);
	nodes.push_back(n5);
	nodes.push_back(n6);
	nodes.push_back(n7);
	nodes.push_back(n8);
	nodes.push_back(n9);
	nodes.push_back(n10);
	nodes.push_back(n11);	

	printVectorNode(nodes);
	vector<struct Node> nodes2 = nodes;
	printVectorNode(nodes2);
	
	cout << endl;

	sort(nodes.begin(), nodes.end(), cmpNode);
	printVectorNode(nodes);

	stable_sort(nodes2.begin(), nodes2.end(), cmpNode);	
	printVectorNode(nodes2);
	return 0;
}
