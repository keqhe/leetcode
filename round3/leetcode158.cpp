
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    //the read data is input into buf
    queue<char> left;
    int read(char *buf, int n) {
        int len = 0;
        int c = 0;
        while (!left.empty()) {
            buf[len++] = left.front();
            left.pop();
            if (len == n)
                return n;
        }
        while (len < n) {
            c = read4(buf+len);
            len += c;
            if (c < 4)
                break;
        }
        for (int i = n; i < len; i ++) {
            left.push(buf[i]);
        }
        int res = min(len, n);
        buf[res] = '\0';
        return res;
    }
};
