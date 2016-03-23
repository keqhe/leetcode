
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        vector<string> v (numRows, "");
        string res;
        int t = 0;
        int direction = 1;//1 up, 0 down
        for (int i = 0; i < s.length(); i++) {
            if (t == 0) {
                v[t].insert(v[t].end(), s[i]);
                t ++;
                direction = 1;
            }
            else if (t > 0 && t < numRows - 1) {
                if (direction == 1) {
                    v[t].insert(v[t].end(), s[i]);
                    t ++;
                }
                else if (direction == 0) {
                    v[t].insert(v[t].end(), s[i]);
                    t --;
                }
            }
            else if (t == numRows - 1) {
                v[t].insert(v[t].end(), s[i]);
                t --;
                direction = 0;
            }
        }
       
        for (int i = 0; i < v.size(); i ++) {
            res += v[i];
        }
        return res;
    }
};
