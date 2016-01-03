#include<iostream>
#include<string>
#include<set>

using namespace std;
/*c++ set is implemented in RB tree or AVL, so insert, erase, and find are logN*/

void printSet(set<int> & s) {
	for (auto x: s)
		cout << x << ' ';
	cout << endl;
}
int main() {
	set<int> s;
	for (int i = 10; i >= 0; i --)
		s.insert(i*10);
	printSet(s);

	if (s.find(50) != s.end())
		cout << "50 is found in s" << endl;
	else
		cout << "50 is NOT found in s" << endl;	
	s.erase(50);
	if (s.find(50) != s.end())
                cout << "50 is found in s" << endl;
	else
                cout << "50 is NOT found in s" << endl;
	
	set<int>::iterator it1 = s.lower_bound(30);//the first element >= 30
	set<int>::iterator it2 = s.upper_bound(60);//the first element > 60;
	s.erase(it1, it2);//it1 points to 30 and it2 points to 70
	cout << "erase [30,60]" << endl;
	printSet(s);

	//note c++ set does not allow duplicated elements
	s.insert(10);
	s.insert(10);
	printSet(s);
	cout << "number of 10s is " << s.count(10) << endl;
	return 0;
}
