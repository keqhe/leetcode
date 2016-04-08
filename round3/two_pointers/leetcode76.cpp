
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";
        int contain_counter = 0;//number of chars s cover
        int l = 0;
        int r = 0;
        unordered_map<char, int> m;//char in t (also in s), the number of times it appear
        unordered_map<char, int> us;//char in t, the number of times it appear
        
        int minLen = numeric_limits<int>::max();
        int minStart = -1;
        for (auto c : t)
            us[c] ++;
        while (r < s.length()) {
            if (us.find(s[r]) != us.end()) {//a char appeared in t
                if (m.find(s[r]) == m.end() || m[s[r]] < us[s[r]])
                    contain_counter ++;
                m[s[r]] ++;
            }
            r ++;
            /*
            //a potential solution, this is the WRONG place to update min
            if (contain_counter == t.length() && r-l < minLen) {
                cout << "a potential solution found" << endl;
                minLen = r-l;
                minStart = l;
            }*/
            //move pointer l to the right and check other potential solutions
            while (contain_counter == t.length()) {
                if (r-l < minLen) {//this is the correct place to update min values
                    cout << "a potential solution found " << l << " " << r << endl;
                    minLen = r-l;
                    minStart = l;
                }
                if (m.find(s[l]) != m.end()) {//a char in t
                    if (m[s[l]] <= us[s[l]]) {
                        contain_counter --;
                    }
                    if (m[s[l]] > 0)
                        m[s[l]] --;
                } 
                l ++;
            }
        }
        if (minStart != -1)
            return s.substr(minStart, minLen);
        else
            return "";
    }
};
