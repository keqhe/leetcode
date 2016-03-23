
class Solution {
public:
    bool isUgly(int n) {
        if (n == 1)
            return true;
        while (n % 2 == 0)
            n /= 2;
        while (n % 3 == 0)
            n /= 3;
        while (n % 5 == 0)
            n /= 5;
        if (n == 1)
            return true;
        else
            return false;
    }
    int nthUglyNumber(int n) {
        
        vector<int> p(1, 1);
        int i2, i3, i5;
        i2 = i3 = i5 = 0;
        int m2, m3, m5;
        
        for (int i = 1; i < n; i ++) {
            m2 = p[i2]*2;
            m3 = p[i3]*3;
            m5 = p[i5]*5;
            
            int next = min(m2, min(m3, m5));
            
            //cout << "i2, i3, i5 and next:" << i2 << 
            
            p.push_back(next);
            
            if (next == m2) {
                i2 ++;
            }
            if (next == m3) {
                i3 ++;
            }
            if (next == m5) 
                i5 ++;
        }
        
        return p[n-1];
    }
};
