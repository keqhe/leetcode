#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int count3(int n) {
	if (n == 1)
		return 1;
	else if (n > 1) {
		int sum = 1;
		for (int i = 1; i < n; i ++)
			sum += count3(i);
		return sum;
	}
}
int count5(int n) {
	vector<int> tmp(n+1, 1);
	for (int i = 2; i <= n; i ++) {
		int sum = 1;
		for (int j = 1; j < i; j ++)
			sum += tmp[j];
		tmp[i] = sum;
	}
	return tmp[n];
}

int count8(int n) {
	if (n == 1)
		return 1;
	else if (n > 1) {
		int a = count8(floor((float)n/2));
		int b = count8(ceil((float)n/2));
		return 2*a*b;
	}
}
int main() {
	cout << count3(4) << endl;
        cout << count3(5) << endl;


	cout << count5(4) << endl;
	cout << count5(5) << endl;

	cout << count8(4) << endl;
        cout << count8(5) << endl;
	return 0;
}
