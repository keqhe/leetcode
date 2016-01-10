#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Node {
        int val;
        int index;
        Node() {
            val = 0;
            index = 0;
        }
        Node (int val, int index) {
            this->val = val;
            this->index = index;
        }
        Node & operator=(const struct Node & n2) {
		this->val = n2.val;
		this->index = n2.index;
	}
	bool operator<(const struct Node & n2) {
		return this->val < n2.val;
	} 
};

int main() {
	struct Node n1 (1, 1);
	struct Node n2;
	n2 = n1;
	cout << n2.val << ' ' << n2.index << endl;

	struct Node n3 (0, 0);
	cout << (n2 < n3) << endl;
	return 0;
}
