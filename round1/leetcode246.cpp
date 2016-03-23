
class Solution {
public:
    //0, 1, (6,9), 8,
    bool isStrobogrammatic(string num) {
        if (num.empty())
            return true;
        int i = 0;
        int j = num.length() - 1;
        while (i <= j) {
            if ((num[i] == '0' && num[j] == '0') || (num[i] == '1' && num[j] == '1')|| (num[i] == '8' && num[j] == '8') || (num[i] == '6' && num[j] == '9') || (num[i] == '9' && num[j] == '6')) {
                i ++;
                j --;
            }
            else 
                return false;
        }
        return true;
    }
};
