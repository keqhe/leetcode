
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
//idea is DFS, see https://leetcode.com/discuss/102377/c-stack-solution-or-depth-first-search-solution
class NestedIterator {
public:
    vector<int> store;
    NestedIterator(vector<NestedInteger> &nestedList) {
        if (nestedList.empty())
            return;
        dfs(nestedList, store);
        //just reverse it
        reverse(store.begin(), store.end());
    }
    void dfs(vector<NestedInteger> &nestedList, vector<int> &store) {
        for (auto x : nestedList) {
            if (x.isInteger()) 
                store.push_back(x.getInteger());
            else {
                dfs(x.getList(), store);
            }
        }
    }
    int next() {
        int res = store.back();
        store.pop_back();
        return res;
    }

    bool hasNext() {
        return !store.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
