
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string curr = "1";
        for (int i = 2; i <= n; i ++) {
            int cnt = 1;
            string next;
            for (int j = 0; j < curr.length(); j ++) {
                if (j+1 == curr.length()) {
                    next += to_string(cnt) + string(1, curr[j]);
                }
                else {
                    if (curr[j] != curr[j+1]) {
                        next += to_string(cnt) + string(1, curr[j]);
                        cnt = 1;
                    }
                    else 
                        cnt ++;
                }
            }
            curr = next;
        }
        return curr;
    }
};
