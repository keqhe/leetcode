
class Solution {
public:
    //ref: https://leetcode.com/discuss/49263/shared-my-ac-c-code-with-explanations
    //the difficult thing is to do it in place
    //ref2: https://leetcode.com/discuss/49263/shared-my-ac-c-code-with-explanations
    void myreverse(string & s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
    void reverseWords(string &s) {
        if (s.empty())
            return;
        int i_used = 0;
        int i = 0;
        int len = s.length();
        
        myreverse(s, 0, len-1);//reverse the whole string
        
        while (i < len) {
            while (i < len && s[i] == ' ')
                i ++;
            int start = i;
            while (i < len && s[i] != ' ')//find a word
                i ++;
            int end = i - 1;
            myreverse(s, start, end);
            
            if (start <= end) {
                for (int j = start; j <= end; j ++) {
                    s[i_used++] = s[j];
                }
                //add a space after word
                if (i_used < len) {
                    s[i_used++] = ' ';
                }
            }
        }
        s.resize(i_used);
        //if there are extra spaces at the end of this string
        while (s.length() > 0 && s.back() == ' ') {
            s.pop_back();
        }
        
    }
};
