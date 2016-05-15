
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0) {
            n --;
            int curr = n % 26;
            char c = curr + 'A';
            res.push_back(c);
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
