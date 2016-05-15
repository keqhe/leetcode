
class Solution {
public:
    //method 1:
    bool isPowerOfThree_method1(int n) {
        long a = 1;
        while (a <= numeric_limits<int>::max()) {
            if (a == n)
                return true;
            a *= 3;
        }
        return false;
    }
    //method 2: google just want to test your math :)
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        double d = log10(n)/log10(3);
        cout << d << endl;
        if (ceil(d) == floor(d))
            return true;
        else
            return false;
    }
};
