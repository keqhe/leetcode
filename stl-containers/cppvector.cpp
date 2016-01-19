/*this is to test of difference of list and vector's insert and erase func*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

void printVector(vector<int> & v) {
	for (int i = 0; i < v.size(); i ++) {
		cout << v[i] << ' ';
	}
	cout << endl;
}
int main() {
	vector<int> v = {1, 2, 3};
	printVector(v);

	v.insert(v.begin(), 0);//0 1 2 3
	v.insert(v.end(), 5);// 0 1 2 3 5
	v.insert(v.begin()+4, 4); // 0 1 2 3 4 5
	printVector(v);

	v.erase(v.begin()+1); //0, 2, 3, 4, 5
	printVector(v);

	//clear vector
	v.clear();
	printVector(v);
	//if a vector is empty, v.begin() == v.end()
	cout << "v.begin() == v.end() ? " << (v.begin() == v.end()) << endl;
	
	return 0;	
}
