#include<iostream>
#include<string>
#include<limits>
#include<vector>

using namespace std;

void matrix_chain_product(vector<int> & nums, vector<vector<int>> & m, vector<vector<int>> & s) {
	//nums[i-1] and nums[i] denotes the dimension of matrix i (i >=1)
	//e.g., when nums.size()=6, there are 5 matrix (labeled from 1 to 5)
	int n = nums.size();
	//let m[i][j] denote the min cost of matrix chain [A(i) A(i+1)... A(j)]
	m.resize(n, vector<int>(n, 0));
	s.resize(n, vector<int>(n, 0));

	for (int i = 1; i < n; i ++)
		m[i][i] = 0;
	for (int l = 2; l < n; l ++) {
	    	for (int i = 1; i + l <= n; i ++) {
			int j = i + l - 1;
			m[i][j] = numeric_limits<int>::max();
			for (int k = i; k < j; k ++) {
				int curr = m[i][k] + m[k+1][j] + nums[i-1]*nums[k]*nums[j];
				if (curr < m[i][j]) {
					m[i][j] = curr;
					s[i][j] = k;
				}
			}
		}
	}
}

void printParens(vector<vector<int>> & s, int i, int j) {
	if (i == j)
		cout << "A" << i;
	else {
		int k = s[i][j];
		cout << "(";
		printParens(s, i, k);
		printParens(s, k+1, j);
		cout << ")";
	}
}

int main() {
	//vector<int> nums = {5, 10, 3, 12, 5, 50, 6};
	vector<int> nums = {8,2,1,2,5};
	vector<vector<int>> m;
	vector<vector<int>> s;
	matrix_chain_product(nums, m, s);
	for (int i = 1; i < nums.size(); i ++) {
		for (int j = i; j < nums.size(); j ++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i < nums.size(); i ++) {
                for (int j = i; j < nums.size(); j ++) {
                        cout << s[i][j] << " ";
                }
                cout << endl;
        }
	printParens(s, 1, nums.size()-1);
	cout << endl;
	return 0;	
}
