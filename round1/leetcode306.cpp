
class Solution {
public:
    //brute force?
    bool isAdditiveNumber(string num) {
        if (num.length() < 3)
            return false;
            
        for (int i = 1; i < (num.length()/2 + 1); i ++) {//len(n3) >= len(n1)
            
            //for (int j = i; j < (num.length()/2 + 1); j ++) {// THIS IS WRONG, e.g., 211738
            for (int j = i; j < num.length(); j ++) {
                string now;
                
                long long n1 = stoll(num.substr(0, i));
                long long n2 = stoll(num.substr(i, j - i + 1));
                
                if (n1 > 1 && num.substr(0, i) [0] == '0' ||
                    n2 > 1 && num.substr(i, j - i + 1)[0] == '0')
                        continue;
                
                long long n3 = n1 + n2;
                string str = to_string(n3);
                
                now += num.substr(0, i) + num.substr(i, j - i + 1) + str;
                while (now.length() < num.length()) {
                    n1 = n2;
                    n2 = n3;
                    n3 = n1 + n2;
                    str = to_string(n3);
                    now += str;
                }
                cout << "i and j " << i << ' ' << j << ' ' << now << endl;
                if (now == num)
                    return true;
            }
        }
        return false;
    }
};
