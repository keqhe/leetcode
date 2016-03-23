
class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        if (s.length() < 2)
            return true;
        //check remove and erase, this is a really cool tool
        string::iterator end = remove(s.begin(), s.end(), ' ');
        s.erase(end, s.end());
        
        //alphanumeric
        //
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                //s2 += string(1, s[i]);
                s2 +=  s[i];
            else if (s[i] >= '0' && s[i] <= '9')
                //s2 += string(1, s[i]);
                s2 +=  s[i];
            else if (s[i] >= 'A' && s[i] <= 'Z')
                //s2 += string(1, s[i]);
                s2 +=  s[i];
        }
        
        s = s2;
        cout << s << endl;
        int i = 0;
        int j = s.length() - 1;
        //aba
        while(i <= j) {
            if (tolower(s[i]) == tolower(s[j])) {
                i ++;
                j --;
            }
            else 
                return false;
        }
        return true;
    }
    //solution 2, use stack
};
