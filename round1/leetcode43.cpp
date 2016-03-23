
class Solution {
public:
    //a clean solution offered by
    //http://www.programcreek.com/2014/05/leetcode-multiply-strings-java/
    void printVector(vector<int> & nums) {
        for (int i = nums.size() - 1; i >= 0 ; i --) {
            cout << nums[i] << ' ';
        }
        cout << endl;
    }
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> dat (len1+len2, 0);// think about 99*99 and 100*100, len1+len2 is enough
        for (int i = 0;i < num1.length(); i ++) {
            for (int j = 0; j < num2.length(); j ++) {
                dat[i+j] += (num1[i] - '0')*(num2[j] - '0');//initially, i mistake += as =
            }
        }
        //cout << "debug1..."<<endl;
        //printVector(dat);
        string res;
        int carry = 0;
        for (int i = 0; i < dat.size(); i ++) {
            int tmp = dat[i] + carry;
            res.insert(res.begin(), tmp%10+'0');
            carry = tmp/10;
        }
        //cout << "debug2..."<<endl;
        //cout << res << endl;
        
        while (res.length() > 1) {
            if (res[0] == '0')
                res.erase(res.begin());
            else
                break;
        }
        //cout << "debug3..."<<endl;
        return res;
    }
};
