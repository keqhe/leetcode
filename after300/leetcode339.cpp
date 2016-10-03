
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    void dfs(NestedInteger& ni, int depth, int & sum) {
        if (ni.isInteger()) {
            sum += ni.getInteger()*depth;
        }
        else {
            for (auto& x : ni.getList()) {
                dfs(x, depth+1, sum);
            }
        }
    }
    int depthSum(vector<NestedInteger>& nestedList) {
        int sum = 0;
        for (auto& x : nestedList) {
            dfs(x, 1, sum);
        }
        return sum;
    }
};
