#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

//algorithm's reverse function is a commonly used routine
int main() {
	string str = "abcd";
	vector<int> v = {1, 2, 3, 4};
	reverse(str.begin(), str.end());
	cout << str << endl;
	reverse(v.begin(), v.end());
	for (auto x : v)
		cout << x << " ";
	cout << endl;
	list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.reverse();
	for (auto x : lst) 
		cout << x << " ";
	cout << endl;
	return 0;
}
