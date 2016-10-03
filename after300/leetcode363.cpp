
class Solution {
public:
    //https://www.youtube.com/watch?v=yCQN096CwWM
    //https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k
    //https://discuss.leetcode.com/topic/48875/accepted-c-codes-with-explanation-and-references
    
    //the time complexity of the following algorithm is O(m*n*m*log(m))
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = numeric_limits<int>::min();
        for (int l = 0; l < n; l ++) {
            vector<int> sums(m, 0);
            for(int r = l; r < n; r ++) {
                for (int i = 0; i < m; i ++) {
                    sums[i] += matrix[i][r];
                }
                //find the max subarray that is no larger than K
                set<int> accumulatedSum;
                accumulatedSum.insert(0);
                int currSum = 0;
                int localMax = numeric_limits<int>::min();
                for (int i = 0; i < m; i ++) {
                    currSum += sums[i];
                    //lower_bound of c++ set, returns the first element's iterator whose value is >= the specified value
                    auto it = accumulatedSum.lower_bound(currSum-k);
                    if (it != accumulatedSum.end()) {
                        localMax = max(localMax, currSum - *it);
                    }
                    accumulatedSum.insert(currSum);
                }
                maxArea = max(maxArea, localMax);
            }
        }
        return maxArea;
    }
};
