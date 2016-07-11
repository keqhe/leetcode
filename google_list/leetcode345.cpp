
class Solution {
public:
    //Vowels
    //consider lower case and upper case
    //C++ : tolower, toupper, isdigit, isalnum
    string reverseVowels(string s) {
        if (s.length() < 2)
            return s;
        vector<int> indecies;
        for (int i = 0; i < s.length(); i ++) {
            if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u') {
                indecies.push_back(i);
            }
        }
        cout << indecies.size() << endl;
        int i = 0; 
        int j = indecies.size()-1;
        while (i < j) {
            swap(s[indecies[i]], s[indecies[j]]);
            i ++;
            j --;
        }
        return s;
    }
};
