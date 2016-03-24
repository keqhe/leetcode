
class Solution {
public:
    //used to compare part1
    bool strCmp1(string s1, string s2) {
        while (s1.length() >= 1) {
            if (s1.front() == '0')
                s1.erase(s1.begin());
            else
                break;
        }
        while (s2.length() >= 1) {
            if (s2.front() == '0')
                s2.erase(s2.begin());
            else
                break;
        }
        
        if (s1.length() == s2.length())
            return s1 < s2;
        else
            return s1.length() < s2.length();
    }
    
    
    int compareVersion(string version1, string version2) {
        if (version1.empty() && version2.empty())
            return 0;
        string str1_p1, str1_p2;
        string str2_p1, str2_p2;
        
        size_t dot1 = version1.find(".");
        if (dot1 != string::npos) {
            str1_p1 = version1.substr(0, dot1);
            str1_p2 = version1.substr(dot1+1);
        }
        else {
            str1_p1 = version1;
        }
        
        size_t dot2 = version2.find(".");
        if (dot2 != string::npos) {
            str2_p1 = version2.substr(0, dot2);
            str2_p2 = version2.substr(dot2+1);
        }
        else {
            str2_p1 = version2;
        }
        
        if (strCmp1(str1_p1, str2_p1))
            return -1;
        else if (strCmp1(str2_p1, str1_p1)) {
            return 1;
        }
        else {//first part is the same
            
            return compareVersion(str1_p2, str2_p2);
        }
    }
};
