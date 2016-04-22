#include<iostream>
#include<string>
#include<vector>

using namespace std;

int LCS(string s1, string s2, vector<vector<int>> &m, vector<vector<int>> &s) {
	if (s1.empty() || s2.empty())
		return 0;	
	int len1 = s1.length();
	int len2 = s2.length();
	//m[i][j] denotes the length of the LCS of s1[0..i-1] and s2[0..j-1]
	m.resize(len1+1, vector<int>(len2+1, 0));
	s.resize(len1+1, vector<int>(len2+1, 0));
	for (int j = 0; j <= len2; j ++)
		m[0][j] = 0;
	for (int i = 1; i <= len1; i ++)
		m[i][0] = 0;
	for (int i = 1; i <= len1; i ++) {
		for (int j = 1; j <= len2; j ++) {
			if (s1[i-1] == s2[j-1]) {
				m[i][j] = m[i-1][j-1] + 1;
				s[i][j] = 3;
			}
			else {
				if (m[i-1][j] >= m[i][j-1]) {
					m[i][j] = m[i-1][j];
					s[i][j] = 1;//from the row above
				}
				else {
					m[i][j] = m[i][j-1];
					s[i][j] = 2;//from the col left
				}
			}
		}
	}
	return m[len1][len2]; 
}

void printLCS(string str, vector<vector<int>> & s, vector<vector<int>> & m, int i , int j) {
	if (i == 0 || j == 0)
		return;
	if (s[i][j] == 3) {
		printLCS(str, s, m, i-1, j-1);
		cout << str[i-1];
	}
	else if (s[i][j] == 1)
		printLCS(str, s, m, i-1, j);
	else if (s[i][j] == 2)
		printLCS(str, s, m, i, j-1);
}
int main() {
	string s1 = "10010101";
	string s2 = "010110110";
	vector<vector<int>> m;
	vector<vector<int>> s;
	cout << "the length of LCS is: " << LCS(s1, s2, m, s) << endl;
	for (int i = 0; i <= s1.length(); i ++) {
		for (int j = 0; j <= s2.length(); j ++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	for (int i = 0; i <= s1.length(); i ++) {
                for (int j = 0; j <= s2.length(); j ++) {
                        cout << s[i][j] << " ";
                }
                cout << endl;
        }
	printLCS(s1, s, m, s1.length(), s2.length());
	cout << endl;
	return 0;
}
