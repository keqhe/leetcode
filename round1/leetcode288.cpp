
class ValidWordAbbr {
public:
    //ref: https://leetcode.com/discuss/62842/a-simple-java-solution-using-map-string-string
    //this ref uses unordered_map<string, string>, which is more efficient
    unordered_map<string, unordered_set<string>> m;
    ValidWordAbbr(vector<string> &dictionary) {
        for (int i = 0; i < dictionary.size(); i ++) {
            int len = dictionary[i].length();
            if (len <= 2)
                continue;
            else {
                string tmp = dictionary[i].front() + to_string(len-2) + dictionary[i].back();
                m[tmp].insert(dictionary[i]);
            }
        }
    }

    bool isUnique(string word) {
        if (word.length() <= 2)
            return true;
        string tmp = word.front() + to_string(word.length()-2) + word.back();
        if (m.find(tmp) != m.end()) {
            if (m[tmp].size() >= 2 || (m[tmp].size() == 1 && m[tmp].find(word) == m[tmp].end()))
                return false;
        }
        return true;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
