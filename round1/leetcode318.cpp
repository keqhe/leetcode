
class Solution {
public:
    //bit manipulation
    //ref: https://leetcode.com/discuss/79738/my-c-solution-using-bit-manipulation-with-explanation
    int convert(string & s) {
        int res = 0;
        for (auto & c : s) {
            res = res | (1 << (c - 'a'));
        }
        return res;
    }
    int maxProduct(vector<string>& words) {
        if (words.empty())
            return 0;
        int res = 0;
        vector<pair<int,int>> tmp;
        for (int i = 0; i < words.size(); i ++) {
            tmp.push_back(make_pair(words[i].length(), convert(words[i])));
        }
        
        for (int i = 0; i < words.size(); i ++) {
            for (int j = i + 1; j < words.size(); j ++) {
                //if (tmp[i].second & tmp[j].second != 0) WRONG!!!
                if ((tmp[i].second & tmp[j].second) != 0)
                    continue;
                res = max(res, tmp[i].first*tmp[j].first);
            }
        }
        return res;
    }
};
