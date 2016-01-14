#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std;

class ValidWordAbbr {
public:
    unordered_map<string, unordered_set<string>> m;
    ValidWordAbbr(vector<string> &dictionary) {
        for (int i = 0; i < dictionary.size(); i ++) {
            int len = dictionary[i].length();
            if (len <= 2)
                continue;
            else {
                string tmp = dictionary[i].front() + to_string(len-2) + dictionary[i].back();
                cout << "in constructor :" << tmp << endl;
		m[tmp].insert(dictionary[i]);
            }
        }
    }

    bool isUnique(string word) {
        if (word.length() <= 2)
            return true;
        string tmp = word.front() + to_string(word.length()-2) + word.back();
        if (m.find(tmp) != m.end()) {
	    cout << "check: " << word << endl;
	    for (auto & x: m[tmp])
		cout << x << " ";
	    cout << endl;
            if (m[tmp].size() >= 2 || (m[tmp].size() == 1 && m[tmp].find(word) == m[tmp].end()))
                return false;
        }
        return true;
    }
};

int main() {
	vector<string> dict = {"hello"};
	class ValidWordAbbr sn(dict);
	cout << sn.isUnique("hello") << endl;
	
	dict = {"deer", "door", "cake", "card"};
	class ValidWordAbbr sn1(dict);
	cout << sn1.isUnique("dear") << endl;
	cout << sn1.isUnique("cart") << endl;
	cout << sn1.isUnique("cane") << endl;
	cout << sn1.isUnique("make") << endl;
	return 0;
	
}
