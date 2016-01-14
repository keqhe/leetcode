#include<iostream>
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
/*
Unordered multisets are containers that store elements in no particular order, 
allowing fast retrieval of individual elements based on their value, 
much like unordered_set containers, but allowing different elements to have equivalent values.
*/

int main() {
	unordered_multiset<int> se;
	for (int i = 0; i < 10; i ++)
		se.insert(i*10);
	se.insert(10);
	se.insert(10);

	for (auto & x : se)
		cout << x << " ";
	cout << endl;

	/*count  */
	cout << se.count(10) << endl;
	se.erase(10);
	for (auto & x : se)
                cout << x << " ";
        cout << endl;
	return 0;
}
