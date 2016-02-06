#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> tmp1 = {"Nine","Eight","Seven","Six","Five","Four","Three","Two","One"};
    vector<int> number1 = {9,8,7,6,5,4,3,2,1};
    vector<string> tmp2 = {"Ninety","Eighty","Seventy","Sixty","Fifty","Forty","Thirty","Twenty"};
    vector<int> number2 = {90,80,70,60,50,40,30,20,10};
    vector<string> tmp3 = {"Billion","Million","Thousand","Hundred"};
    vector<int> number3 = {1000000000, 1000000, 1000, 100};
    
    vector<string> tmp0 = {"Ten","Eleven", "Twelve", "Thirteen", "Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string to_literal(int num) {
        string res;
        if (num >= 100) {
            int t = num / 100;
            num -= t*100;
            res += tmp1[9-t] + " Hundred" + " ";
        }
        while (num > 0) {
            int i;
            if (num >= 10 && num < 20) {
                for (int i = 0; i < tmp0.size(); i ++) {
                    if (num - 10 == i) {
                        res += tmp0[i] + " ";
                        num -= num;
                    }
                }
            }
            if (num >= 20) {
                for (i = 0; i < number2.size(); i ++) {
                    if (num >= number2[i]) {
                        res += tmp2[i] + ' ';
                        num -= number2[i];
                        break;
                    }
                }
            }
            else {
                for (i = 0; i < number1.size(); i ++) {
                    if (num >= number1[i]) {
                        res += tmp1[i] + ' ';
                        num -= number1[i];
                        break;
                    }
                }
            }
        }
        return res;
    }
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string res;
        
        while (num > 0) {
            if (num < 1000) {
                res += to_literal(num);
                num -= num;
            }
            else {
                int i = 0;
                int prefix = 0;
                for (i = 0; i < number3.size(); i ++) {
                    int x = number3[i];
                    if (num >= x) {
                        prefix = num / x;
                        num -= x*prefix;
                        break;
                    }
                }
            
                string str = to_literal(prefix);
                cout << str << endl;
                res += str + tmp3[i] + " ";
            }
        }
        if (res.back() == ' ')
            res.pop_back();
        return res;
    }
};

int main() {
	class Solution sn;
	cout << sn.numberToWords(123) << endl;
	cout << sn.numberToWords(123457) << endl;
	cout << sn.numberToWords(123457898) << endl;
	return 0; 
}
