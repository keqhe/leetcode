
class Solution {
public:
    //another way to look at this traangle
    /*
        [ [1]
          [1 1]
          [1 2 1]
          [1 3 3 1]
          [1 4 6 4 1]
        ]
    */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; i ++) {
            if (res.empty()) {
                vector<int> tmp;
                tmp.push_back(1);
                res.push_back(tmp);
            }
            else {
                vector<int> last = res.back();
                vector<int> curr (i, 1);
                for (int j = 1; j < last.size(); j ++) {
                        curr[j] = last[j-1] + last[j];
                }
                res.push_back(curr);
            }
        }
        return res;
    }
};
