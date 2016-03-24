
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0) {
            int d = (n-1) % 26;
            
            res.push_back(d+'A');
            n = (n-1) / 26;
        }
        reverse(res.begin(), res.end());
    
        return res;
    }
    
};
