class Solution {
public:
    string addStr(string s1, string s2) {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        string res;
        int carry = 0;
        int i = 0;
        int j = 0;
        for (;i < s1.length() && j < s2.length(); i ++, j ++) {
            int curr = s1[i] - '0' + s2[j] - '0' + carry;
            res.push_back('0' + curr%10);
            carry = curr / 10;
        }
        while (i < s1.length()) {
            int curr = s1[i] - '0' + carry;
            res.push_back('0' + curr%10);
            carry = curr / 10;
            i ++;
        }
        while (j < s2.length()) {
            int curr = s2[j] - '0' + carry;
            res.push_back('0' + curr%10);
            carry = curr / 10;
            j ++;
        }
        if (carry)
            res.push_back(carry+'0');
        reverse(res.begin(), res.end());
        return res;
    }
    bool backtracking(string num, int pos, string prev1, string prev2) {
        if (pos >= num.length())
            return true;
        for (int i = pos; i < num.length(); i ++) {
            string s1 = num.substr(pos, i-pos+1);//including i

            if (s1.front() == '0' && s1.length() > 1)
                break;
            if (s1 != addStr(prev1, prev2)) {
                continue;
            }
            string s = addStr(s1, prev2);
            cout << "debug1: " << prev1 <<" " << prev2 << " " << s1 << " " << s << " " << i+1 << " " << i+1+s.length() << endl;
            
            if (i+1 == num.length())
                return true;//found a valid solution
            if (i+s.length() > num.length()) {//e.g., 199100, "112358"
                break;
            }
            string cmp = num.substr(i+1, s.length());
            if (cmp == s) {
                cout << "debug2: " << prev1 <<" " << prev2 << " " << s1 << " " << s << " " << i+1+s.length() << endl;
                if (backtracking(num, i+1+s.length(), s1, cmp)) //
                    return true;
            }
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        if (num.length() < 3)
            return false;
        for (int i = 0; i <= num.length()/2; i ++) {
            string prev1 = num.substr(0, i+1);
            if (prev1.front() == '0' && prev1.length() > 1)
                continue;
            for (int j = i+1; j < num.length()-1; j ++) {
                string prev2 = num.substr(i+1, j-i);
                if (prev2.front() == '0' && prev2.length() > 1)
                    continue;
                if (backtracking(num, j+1, prev1, prev2))
                   return true;
            }
        }
        
        return false;
    }
};
