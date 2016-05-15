
class Solution {
public:
    int comparePart1(string s1, string s2) {
        while (!s1.empty()) {
            if (s1.front() == ' ' || s1.front() == '0')
                s1.erase(s1.begin());
            else
                break;
        }
        while (!s2.empty()) {
            if (s2.front() == ' ' || s2.front() == '0')
                s2.erase(s2.begin());
            else
                break;
        }
        if (s1.length() != s2.length()) {
            if (s1.length() > s2.length())
                return 1;
            else
                return -1;
        }
        else {
            if (s1 < s2)
                return -1;
            else if (s1 > s2)
                return 1;
            else
                return 0;
        }
    }
   
    int compareVersion(string version1, string version2) {
        if (version1.empty() && version2.empty()) //important to terminate the recursion.
            return 0;
        string v1_p1;
        string v2_p1;
        string v1_p2;
        string v2_p2;
        size_t pos1 = version1.find('.');
        if (pos1 == string::npos) {
            v1_p1 = version1;
            v1_p2 = "";
        }
        else {
            v1_p1 = version1.substr(0, pos1);
            v1_p2 = version1.substr(pos1+1);
        }
        
        size_t pos2 = version2.find('.');
        if (pos2 == string::npos) {
            v2_p1 = version2;
            v2_p2 = "";
        }
        else {
            v2_p1 = version2.substr(0, pos2);
            v2_p2 = version2.substr(pos2+1);
        }
        int part1 = comparePart1(v1_p1, v2_p1);
        cout << part1 << endl;
        if (part1 == 1)
            return 1;
        else if (part1 == -1)
            return -1;
        else {
            return compareVersion(v1_p2, v2_p2);
        }
    }
};
