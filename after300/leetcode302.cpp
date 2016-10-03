
class Solution {
public: 
    //first idea is BFS or DFS
    //second is binary search: https://discuss.leetcode.com/topic/29006/c-java-python-binary-search-solution-with-explanation
    int searchCol(int l, int r, int t, int b, vector<vector<char>>& image, bool flag) {
        while (l < r) {
            int k = t;
            int mid_col = l + (r-l)/2;
            while (k < b && image[k][mid_col] == '0')
                k ++;
            if (flag == true) {
                if (k < b)
                   r = mid_col;
                else
                   l = mid_col + 1;
            }
            else {
                if (k >= b) //all zeros
                    r = mid_col;
                else
                    l = mid_col + 1;
            }
        }
        return l;
    }
    int searchRow(int t, int b, int l, int r, vector<vector<char>>& image, int flag) {
        while (t < b) {
            int k = l;
            int mid_row = t + (b-t)/2;
            while (k < r && image[mid_row][k] == '0')
                k ++;
            if (flag == true) {
                if (k < r)
                    b = mid_row;
                else
                    t = mid_row + 1;
            }
            else {
                if (k >= r)
                    b = mid_row;
                else
                    t = mid_row + 1;
            }
        }
        return t;
    }
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty() || image[0].empty())
            return 0;
        int m = image.size();
        int n = image[0].size();
        int left = searchCol(0, y, 0, m, image, true);
        // why pass n in (why not n-1?), because we may want it return right == n
        int right = searchCol(y+1, n, 0, m, image, false);
        int top = searchRow(0, x, 0, n, image, true);
        int bottom = searchRow(x+1, m, 0, n, image, false);
        
        return (right - left) * (bottom - top);
    }
};
