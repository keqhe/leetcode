
class Solution {
public:
    //unsigned int 32's max: 2147483647 (more than 2 billion)
    
    //take a number < 1000, and convert it to english 
    string helper(int num) {
        vector<string> v1 = {"XX", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                             "Nine"};
        vector<string> v2 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v3 = {"XX", "XX", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        string res;
        if (num > 0) {
            int h = num / 100;
            if (h > 0)
                res += v1[h] + " Hundred";
                
            h = num % 100;
            
            if (h > 0 && h < 10) {
                if (res.length() != 0) res += ' ';
                res += v1[h];
                return res;
            }
            else if (h >= 10 && h < 20) {
                if (res.length() != 0) res += ' ';
                res += v2[h%10];
                return res;
            }
            else if (h >= 20 && h < 100) {
                if (res.length() != 0) res += ' ';
                res += v3[h/10];
                
                if (h%10) {
                    if (res.length() > 0) res += ' ';
                    res += v1[h%10];
                }
                return res;
            }
        }
        
    }
    string numberToWords(int num) {
        vector<string> unit = {"", "Thousand", "Million", "Billion"};
        if (num == 0)
            return "Zero";
            
        string res;
        int i = 0;
        while (num > 0) {
            int temp = num % 1000;
            cout << " temp " << temp << endl; 
            if (temp) {
                if (res.length() > 0)
                    res = helper(temp) + ' ' + unit[i] + ' ' + res;
                else
                    res = helper(temp) + ' ' + unit[i];
            }
            i ++;
            num = num / 1000;
        }
        
        if (res[res.length()-1] == ' ') res.erase(res.end()-1);
        
        return res;
    }
};
