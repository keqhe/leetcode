#include<iostream>
#include<string>

using namespace std;


int main() {
	string str = "abcd";
	cout << "string iteration, method 1 ..." << endl;
	for (int i = 0; i < str.length(); i ++) {
		cout << str[i] << ' ';
	}
	cout << endl;

	cout << "string iteration, method 2 ..." << endl;
        for (string::iterator it = str.begin(); it != str.end(); it ++) {
                cout << *it << ' ';
        }
        cout << endl;

	cout << "string add chars ..." << endl;
	str.append(1,'e');
	str.push_back('f');
	str += string(1, 'g');
	str.pop_back();
	for (int i = 0; i < str.length(); i ++) {
                cout << str[i] << ' ';
        }
        cout << endl;

	cout << "check whether a string is empty or not..." << endl;
	cout << str.empty() << endl;
	cout << (str.length() == 0) << endl;


	cout << "string insert...(insert right before the pos specified.)" << endl;
	str.insert(0, 1, '1');
	str.insert(str.begin(), '0');
	str.insert(str.end(), 'g');
	for (int i = 0; i < str.length(); i ++) {
                cout << str[i] << ' ';
        }
        cout << endl;

	cout << "erase chars from string..." << endl;
	str.erase(str.begin());
	str.erase(str.begin()+1);
	for (int i = 0; i < str.length(); i ++) {
                cout << str[i] << ' ';
        }
	cout << endl;
	str.erase(str.end()-1);
	for (int i = 0; i < str.length(); i ++) {
                cout << str[i] << ' ';
        }
        cout << endl;
	cout << "check substr... " << endl;
	string sub = "abcd";
	cout << sub.substr(0) << endl;
	sub += sub[0];
	cout << sub << endl;
	return 0;
}
