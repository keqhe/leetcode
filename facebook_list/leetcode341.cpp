
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
class NestedIterator {
public:
    vector<int> store;
    void dfs(vector<NestedInteger> &nestedList, vector<int>& store) {
        for (NestedInteger x : nestedList) {
            if (x.isInteger()) {
                store.push_back(x.getInteger());
            }
            else {
                dfs(x.getList(), store);
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList, store);
        reverse(store.begin(), store.end());
    }

    int next() {
        int val = store.back();
        store.pop_back();
        return val;
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
