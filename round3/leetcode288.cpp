
class ValidWordAbbr {
public:
    
    unordered_map<string, multiset<string>> um;
    string abbr(string s) {
        if (s.length() <= 2)
            return s;
        else {
            string res;
            res += s[0];
            res += to_string(s.length()-2);
            res += s.back();
            return res;
        }
    }
    ValidWordAbbr(vector<string> &dictionary) {
        if (dictionary.empty())
            return;
        for (auto s : dictionary) {
            string a = abbr(s);
            um[a].insert(s);
        }
    }

    bool isUnique(string word) {
        string a = abbr(word);
        cout << a << endl;
        if (um.find(a) != um.end()) {
                return *(um[a].begin()) == word && *(um[a].begin()) == *(um[a].rbegin());
        }
        else 
            return true;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
