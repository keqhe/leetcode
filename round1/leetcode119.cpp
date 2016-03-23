
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r (rowIndex+1, 1);
        for (int row = 0; row <= rowIndex; row ++) {
            if (row == 0)
                r[0] = 1;
            if (row == rowIndex)
                r[row] = 1;
            for (int i = row - 1; i >= 1;  i--) {
                r[i] = r[i-1] + r[i];
            }
            /*
            for (int i = 0; i <= row; i ++)
                cout << r[i] << ' ';
            cout << endl;
            */
        }
        return r;
    }
};
