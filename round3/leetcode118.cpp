
class Solution {
public:
    /*
    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1
    */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i ++) {
            vector<int> last;
            if (!res.empty()) {
                last = res.back();
                for (int j = 0; j < last.size()-1; j ++)
                    last[j] = last[j+1] + last[j];
                last.insert(last.begin(), 1);
            }
            else
                last.push_back(1);
            res.push_back(last);
        }
        return res;
    }
};
