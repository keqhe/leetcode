class Solution {
public:
    //https://discuss.leetcode.com/topic/23054/my-clean-java-solution-very-easy-to-understand
    vector<string> LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> TENS = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> THOUSANDS = {"", "Thousand", "Million", "Billion"};
    
    string helper(int num) {
        if (num == 0)
            return "";
        else if (num < 20) {
            return LESS_THAN_20[num] + " ";
        }
        else if (num < 100) {
            return TENS[num/10] + " " + helper(num % 10);
        }
        else {
            return LESS_THAN_20[num/100] + " Hundred " + helper(num%100); 
        }
    }
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string res;
        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                res = helper(num % 1000) + THOUSANDS[i] + " "+ res;
            }
            num /= 1000;
            i ++;
        }
        while (res.size() > 1 && res.back() == ' ')
            res.pop_back();
        return res;
    }
};
