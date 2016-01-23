#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Codec {
public:
    //ref: https://leetcode.com/discuss/55020/ac-java-solution
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto & x : strs) {
            int len = x.length();
            res += to_string(len) + ":" + x;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        if (s.empty()) 
            return res;
        int i = 0;
        string tmp;
        while (i < s.length()) {
            size_t found = s.find(":", i);//e.g., "3:abc", "0:0:"
            int len = stoi(s.substr(i, found-i));
            tmp = s.substr(found+1, len);
            i = found + 1 + len;
	    cout << "tmp:" << tmp << "   " << "i:" << i << endl;
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
	vector<string> test;
	test.push_back("");
	test.push_back("");
	
	class Codec sn;
	string a = sn.encode(test);
	cout << a << endl;
	vector<string> b = sn.decode(a);
	for (auto & x : b) {
		cout << x << " ";
	}
	cout << endl;

	test.clear();
	test.push_back("hello");
	test.push_back("world!");
	a = sn.encode(test);
	b = sn.decode(a);
	for (auto & x : b) {
                cout << x << " ";
        }
        cout << endl;
	return 0;
}
