
class Solution {
public:
    //
    void reverseWords(string &s) {
        //process heading spaces
        while (!s.empty() && s.front() == ' ')
            s.erase(s.begin());
        //process tailing spaces
        while (!s.empty() && s.back() == ' ')
            s.pop_back();
        if (s.empty() || s.length() == 1)
            return;
        vector<string> tmp;
        int i = 0;
        int j = 0;
        while (i < s.length()) {
            while (i < s.length()&& s[i] != ' ') {//this also include the case where i = s.length()-1
                i ++;
            }
            string t = s.substr(j, i-j);
            tmp.push_back(t);
            while (i < s.length() && s[i] == ' ') {
                i ++;
            }
            j = i;
        }
        reverse(tmp.begin(), tmp.end());
        s.clear();
        for (int k = 0; k < tmp.size(); k ++) {
            if (k == tmp.size()-1)
                s += tmp[k];
            else
                s += tmp[k] + ' ';
        }
        
    }
};
