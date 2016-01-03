#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;
//c++'s unordered_set is implemented in hash table, so on average it is O(1),
//but in the worst(hash collision), O(n)
void printUnorderedSet(unordered_set<int> & us) {
	for (auto x : us) 
		cout << x << ' ';
	cout << endl;
}
int main() {
	unordered_set<int> us;
	for (int i = 10; i >= 0; i --) 
		us.insert(i*10);
	printUnorderedSet(us);
	
	if (us.find(50) != us.end()) 
		cout << "50 is found in us" << endl;
	else 
		cout << "50 is not found in us" << endl;
	us.erase(50);
	if (us.find(50) != us.end())
                cout << "50 is found in us" << endl;
        else
                cout << "50 is not found in us" << endl;

	us.erase(200);

	//unordered_set's each element must be unique
	us.insert(10);
	us.insert(10);	
	printUnorderedSet(us);

	//count returns 1 if exist, otherwise 0	
	cout << "number of 10s in us " << us.count(10) << endl;
	return 0;
}
