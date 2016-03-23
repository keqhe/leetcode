
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
        char tmp[4];
        int i = 0;
        
        while (i < n) {
            int a = read4(tmp);
            if (a == 0)
                break;
            for (int j = 0; j < a; j ++) {
                *buf ++ = tmp[j];
                i ++;
                if (i >= n)
                    break;
            }
        }
        
        return i;
    }
};
