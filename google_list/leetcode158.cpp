
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    deque<char> de;
    int read(char *buf, int n) {
        int sum = 0;
        while (!de.empty()) {
            *(buf+sum) = de.front();
            de.pop_front();
            sum ++;
            if (sum == n)
                return sum;
        }
        //still need to call read4
        do {
            int curr = read4(buf+sum);
            sum += curr;
            if (curr < 4)
                break;
        } while (sum < n);
        
        if (sum == n)
            return n;
        else if (sum < n)
            return sum;
        else {//sum > n
            for (int i = n; i < sum; i ++) {
                de.push_back(*(buf+i));
            }
            *(buf+n) ='\0';//terminate the string
            return n;
        }
    }
};
