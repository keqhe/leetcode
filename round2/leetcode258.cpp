
class Solution {
public:
    //okay, first a naive solution to process string and integer
    int addDigits_solution1(int num) {
        string tmp = to_string(num);
        while (tmp.length() > 1) {
            int curr = 0;
            for (int i = 0; i < tmp.length(); i ++) {
                curr += tmp[i] - '0';
            }
            tmp = to_string(curr);
        }
        
        return stoi(tmp);
    }
    //then, the fast solution is to use a fomular
    //digital root of n = 1 + ( (n - 1) % 9 )
    int addDigits(int num) {
        if (num == 0)
            return 0;
        else    
            return 1 + (num-1) % 9;
    }
};
