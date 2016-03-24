
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    //what's the difference of reading once and reading multiple times?
    //see ref:https://leetcode.com/discuss/84216/what-the-difference-between-call-once-and-call-multiple-times
    //
    //ref: using a queue:
    //https://leetcode.com/discuss/29952/18-lines-clean-and-neat-c-solution-2ms
    //Key Idea: First Read from internal buffer, then file, then push superfluous to the internal buffer.
    queue<char> left;
    int read(char *buf, int n) {
       int len = 0;
       int c;
       while (!left.empty()) {
           buf[len++] = left.front();
           left.pop();
           if (len == n)
              return len;
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
       int e = min(len, n);
       buf[e] = '\0';
       return e;
    }
};
