
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
            int x = read4(buf+sum);//key is here...
            sum += x;
            if (x < 4)
                break;
        } while (sum < n);
        
        if (sum <= n) {
            return sum;
        }
        else
            return n;
    }
};
