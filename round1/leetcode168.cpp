
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        if (n <= 0)
            return res;
        
        while (n > 0) {
            n --; //this is the key
            int a = n % 26;
            res += string(1, 'A' + a);
            n /= 26;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
