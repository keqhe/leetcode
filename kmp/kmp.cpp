#include<iostream>
#include<string>
#include<vector>

using namespace std;

int strStr(string s, string ps) {//s is the target string, ps is pattern string
	if (s.length() < ps.length())
		return -1;
	if (ps.empty())
		return 0;
	int m = ps.length();
	int n = s.length();
	vector<int> next(m, 0);
	//compute next array
	for (int i = 1, matched_pos = 0; i < m-1;) {
		if (ps[i] == ps[matched_pos]) {
			next[i] = matched_pos + 1;
			i ++;
			matched_pos ++;
		}
		else {
			if (matched_pos > 0)
				matched_pos = next[matched_pos - 1];
			else
				i ++;
		}
		
	}

	//
	for (int i = 0, matched_pos = 0; i < n; ) {
		if (s[i] == ps[matched_pos]) {
			if (matched_pos == m -1)
				return (i - m + 1);
			else {
				i ++;
				matched_pos ++;
			}
		}
		else {
			if (matched_pos > 0) 
				matched_pos = next[matched_pos - 1];
			else
				i ++;
		}
	}
	return -1;
}

int main() {
	string s = "good man";
	string ps = "an";
	cout << strStr(s, ps) << endl;
	return 0;
}
