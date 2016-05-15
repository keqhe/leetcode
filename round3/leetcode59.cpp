
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if (n < 1)
            return res;
        res.resize(n, vector<int>(n, 0));
        int t = 0;//top
        int b = n-1;//bottom
        int l = 0; //left
        int r = n-1;//right
        
        int cnt = 1;
        while (t < b && l < r) {
            //top row
            for (int j = l; j <= r; j ++) {
                res[t][j] = cnt ++;
            }
            t ++;
            //right column
            for (int i = t; i <= b; i ++) {
                res[i][r] = cnt ++;
            }
            r --;
            //bottom row
            for (int j = r; j >= l; j --) {
                res[b][j] = cnt ++;
            }
            b --;
            //left column
            for (int i = b; i >= t; i --) {
                res[i][l] = cnt ++;
            }
            l ++;
        }
        //if one row left
        if (l <= r) {
            for (int j = l; j <= r; j ++)
                res[t][j] = cnt ++;
        }
        else if (t <= b) {
            for (int i = t; i <= b; i ++) 
                res[i][l] = cnt ++;
        }
        
        return res;
    }
};
