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
	return 0;
}
