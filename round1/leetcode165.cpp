
class Solution {
public:
    //2.3.1 <= 2.3.1
    //1.2.7 < 12.1
    //1.2 < 1.2.0
    //1.2.1 
    //"." "1.1" ??
    //"1" "2"
    unsigned long getNum(string s, int &pos) {
        unsigned long res = 0;
        while(pos < s.length()) {
            if (s[pos] == '.') {
                pos ++;
                break;
            }
            else {
                res = 10*res + s[pos] - '0';
                pos ++;
            }
        }
        return res;
    }
    int compareVersion(string version1, string version2) {
        
        int l1 = version1.length();
        int l2 = version2.length();
        int i = 0;
        int j = 0;
        unsigned long num1, num2;
        
        while(i < l1 && j < l2) {
            num1 = getNum(version1, i);
            num2 = getNum(version2, j);
            //cout << "hi " << num1 << ' ' << num2 << endl;
            if (num1 > num2)
                return 1;
            else if (num1 < num2)
                return -1;
        }
        //leftover
        while (i < l1) {
            if (version1[i] != '0' && version1[i] != '.')
                return 1;
            i ++;
        }
        
        while (j < l2) {
            if (version2[j] != '0' && version2[j] != '.')
                return -1;
            j ++;
        }
        
        return 0;
    }
    
};
