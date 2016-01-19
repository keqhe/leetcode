#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

/*Calculates the number of elements between [first, last) */
int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	cout << distance(v.begin(), v.end()) << endl;
	cout << *(v.begin()+3) << endl;
	cout << distance(v.begin(), v.begin()+3) << endl;
	
	multiset<int> m = {1, 5, 4, 3, 2};
	for (auto & x : m ) 
		cout << x << " ";
	cout << endl;
	return 0;
}
