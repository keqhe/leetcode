#include<iostream>
#include<string>
#include<limits>

using namespace std;

//check whether an interge is power of 2

class Solution {
public:
    //idea 1: left shift 
    bool isPowerOfTwo_idea1(int n) {
        
        for (int i = 0; i < 32; i ++) {
            long b = ((long)1 << i);
            if (n == b)
                return true;
            else if (n < b)
                return false;
        }
    }
    //idea: if an integer is power of 2, then only 1 bit in 1
    bool isPowerOfTwo(int n) {
        return (n > 0) && (n & (n-1)) == 0;
    }
};

int main() {
	class Solution sn;
	cout << sn.isPowerOfTwo(8) << endl;
	cout << sn.isPowerOfTwo_idea1(1073741825) << endl;

	cout << (1 << 31) << endl;
	cout << numeric_limits<int>::max() << endl;
	return 0;
}
