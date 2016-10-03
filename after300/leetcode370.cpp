
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        for (auto x : updates) {
            int start = x[0];
            int end = x[1];
            int inc = x[2];
            res[start] += inc;
            if (end+1 < length)
                res[end+1] += -inc;
        }
        
        for (int i = 1; i < length; i ++) {
            res[i] = res[i] + res[i-1];
        }
        return res;
    }
};
