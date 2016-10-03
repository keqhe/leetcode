
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
    //BFS is okay here. https://discuss.leetcode.com/topic/49488/java-ac-bfs-solution
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> q;
        int prev_level = 0;
        int total = 0;
        for (const auto& x : nestedList) {
            q.push(x);
            cout << "debug" << endl;
        }
        while (!q.empty()) {
            int size = q.size();
            int curr_level = prev_level;
            for (int i = 0; i < size; i ++) {
                NestedInteger ni = q.front();
                q.pop();
                if (ni.isInteger()) {
                    curr_level += ni.getInteger();
                }
                else {
                    for (auto& x : ni.getList()) {
                        q.push(x);
                    }
                }
            }
            cout << "curr_level :" << curr_level << endl;
            total += curr_level;
            prev_level = curr_level;
        }
        return total;
    }
};
