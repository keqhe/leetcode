
class Solution {
public:
    //https://discuss.leetcode.com/topic/52865/my-solution-using-binary-search-in-c/10
    //about lower_bound and upper_bound with vectors, see http://www.cplusplus.com/reference/algorithm/upper_bound/
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        while (left < right) {
            int midv = left + (right - left)/2;
            int count = 0;
            for (int i = 0; i < n; i ++) {
                vector<int> &row = matrix[i];
                //number of elements in row whose value is >= midv
                count += std::upper_bound(row.begin(), row.end(), midv) - row.begin();
            }
            if (count < k) 
                left = midv + 1;
            else
                right = midv;
        }
        return left;
    }
};
