#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;

class ZigzagIterator {
public:
    //ref:https://leetcode.com/discuss/63037/simple-java-solution-for-k-vector
    
    list<vector<int>::iterator> mylist;
    vector<int>::iterator v1end;
    vector<int>::iterator v2end;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        mylist.push_back(v1.begin());
        mylist.push_back(v2.begin());
        v1end = v1.end();
        v2end = v2.end();
    }

    int next() {
        vector<int>::iterator curr = mylist.front();
        int val = *curr;
        //cout << val << endl;
        advance(curr, 1);
	mylist.pop_front();
        if (curr != v1end && curr != v2end) {
            mylist.push_back(curr);
        }
        return val;
    }

    bool hasNext() {
        return !mylist.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

/*the difference between C++ iterator and Java iterator*/
/*http://stackoverflow.com/questions/56347/iterators-in-c-stl-vs-java-is-there-a-conceptual-difference*/
int main() {
	vector<int> v1 = {1, 2};
	vector<int> v2 = {3, 4, 5, 6};
	class ZigzagIterator zi (v1, v2);
	while (zi.hasNext()) {
		cout << zi.next() << " ";
	}
	cout << endl;
	return 0;
}
