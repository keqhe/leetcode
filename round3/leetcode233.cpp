
class Solution {
public:
    //the naive method is to count the number of 1's in each number in range...
    //the basic idea is assume each digit is 1 and count how many possibilities are there
    //take 392, 
    //312 and 302 are examples
    //392: (3*10+10) + 
    int countDigitOne(int n) {
        if (n < 1)  
            return 0;
        int count = 0;
        int mod = 1;
        int q = n;
        do {
            int digit = q % 10;
            q = q / 10;
            
            if (digit > 1) {
                count += q*mod + mod;
            }
            else if (digit == 1) {
                count += q*mod + n%mod + 1;
            }
            else {
                count += q*mod;
            }
            
            mod *= 10;
        }while (q > 0);
        
        return count;
    }
};
