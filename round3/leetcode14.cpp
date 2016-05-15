
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        int cnt = 0;
        bool stop = false;
        while (cnt < strs[0].length() && !stop) {
            for (int i = 1; i < strs.size(); i ++) {
                if (cnt < strs[i].length()) {
                    if (strs[0][cnt] != strs[i][cnt]) {
                        stop = true;
                        break;
                    }
                }
                else {
                    stop = true;
                    break;
                }
            }
            if (!stop)
                cnt ++;
        }
        return strs[0].substr(0, cnt);
    }
    //the old method seems to be better, see https://github.com/keqhe/leetcode/blob/master/round2/leetcode14.cpp
};
