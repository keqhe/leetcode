
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int sum = 0;
        do {
            //int a = read4(buf); //this is WRONG, think why
            int a = read4(buf+sum);
            sum += a;
            if (a < 4)
                break;
        } while (sum < n);
        return min(n,sum);
    }
};
