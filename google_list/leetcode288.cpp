
class ValidWordAbbr {
public:
    unordered_map<string, unordered_set<string>> um;
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto w : dictionary) {
            string str;
            if (w.length() <= 2)
                str = w;
            else {
                str = w.front() + to_string(w.length()-2) + w.back();//e.g., "abcd"
            }
            um[str].insert(w);
        }
    }

    bool isUnique(string word) {
        string str;
        if (word.length() <= 2)
            str = word;
        else {
            str = word.front() + to_string(word.length()-2) + word.back();
        }
        if (um.find(str) == um.end())
            return true;
        else {
            auto x = um[str];
            //cout << "debug: " << x.size() << endl;
            //cout << *x.begin() << endl;
            if (x.size() > 1)
                return false;
            else {
                if (*x.begin() == word)
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
