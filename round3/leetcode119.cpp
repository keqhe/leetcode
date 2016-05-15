
class Solution {
public:
    /*
    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1
    */
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for (int i = 0; i <= rowIndex; i ++) {
            if (res.empty()) {
                res.push_back(1);
            }
            else {
                for (int j = 0; j < res.size()-1; j ++) {
                    res[j] = res[j+1] + res[j];
                }
                res.insert(res.begin(), 1);
            }
        }
        return res;
    }
};
