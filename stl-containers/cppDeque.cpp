#include<iostream>
#include<string>
#include<deque>

/*CPP double-ended queue*/
using namespace std;
int main() {
	deque<int> de;
	cout << "deque push_back..." << endl;
	for (int i = 0; i < 10; i ++)
		de.push_back(i);
	cout << "deque pop front..." << endl;
	while (!de.empty()) {
		int a = de.front();
		cout << a << ' ';
		de.pop_front();
	}

	cout << "\ndeque push_front..." << endl;
	for (int i = 0; i < 10; i ++) 
		de.push_front(i);
	cout << "deque pop_back..." << endl;
	while (!de.empty()) {
		int a = de.back();
		cout << a << ' ';
		de.pop_back();
	}
	cout << endl;
	cout << "deque push_back..." << endl;
	for (int i = 0; i < 10; i ++)
		de.push_back(i);
	for (int i = 0; i < de.size(); i ++)
		cout << de[i] << endl;
	cout << endl;
	return 0;
}
