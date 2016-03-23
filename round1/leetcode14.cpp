
class Solution {
public:
    //"abc", "a"
    //"abc", "ab"
    //"abc", "ac"
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        long len = 0;
        long i;
        if (strs.size() > 0)
            len = strs[0].length();
            
        for (long i = 0; i < strs.size(); i ++) {
            if (strs[i].length() < len)
                len = strs[i].length();
        }
        bool same = true;
        for (i = 0; i < len; i ++) {
            for (long j = 1; j < strs.size(); j ++) {
                same = (strs[j][i] == strs[j-1][i]);
                if (!same)
                    break;//this only breaks out the first loop
            }
            if (!same)
                return strs[0].substr(0,i);//if all of them are the same, then !same is never triggered
        }
        if (strs.size() > 0)//what if strs = []?
            s = strs[0].substr(0, i);
        return s;
    }
};
