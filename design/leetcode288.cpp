#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class ValidWordAbbr {
public:
    unordered_map<string, unordered_set<string>> m;
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto tmp : dictionary) {
            if (tmp.length() <= 2)
                m[tmp].insert(tmp);
            else {
                string tmp2 = tmp.front() + to_string(tmp.length()-2) + tmp.back();
                m[tmp2].insert(tmp);
            }
        }
    }

    bool isUnique(string word) {
        string tmp;
        if (word.length() <= 2)
            tmp = word;
        else
            tmp = word.front() + to_string(word.length()-2) + word.back();
        if (m.find(tmp) == m.end())
            return true;
        else {
            auto it = m.find(tmp);
            auto x = it->second;
            if (x.size() >= 2)
                return false;
            else {//==1
                //either is fine, below
                if (*(x.begin()) == word)
                //if (x.count(word) == 1)
                    return true;
                else
                    return false;
            }
        }
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");

int main() {
	class ValidWordAbbr vw;
	return 0;
}
