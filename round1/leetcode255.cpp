
class Solution {
public:
    //     4
    //    / \
    //   2   6
    //  /\  / \
    // 1  3 5  7
    //[4 2 1 3 6 5 7]
    //ref: https://leetcode.com/discuss/51543/java-o-n-and-o-1-extra-space
    bool verifyPreorder(vector<int>& preorder) {
        int low = numeric_limits<int>::min();
        int i = -1;
        for (auto & x : preorder) {
            if (x < low)
                return false;
            while (i >= 0 && preorder[i] < x) {
                low = preorder[i];
                i --;
            }
            preorder[++i] = x;
        }
        return true;
    }
    bool verifyPreorder__(vector<int>& preorder) {
        stack<int> st;
        int low = numeric_limits<int>::min();
        for (auto & x : preorder) {
            if (x < low)
                return false;
            while (!st.empty() && st.top() < x) {
                low = st.top();
                st.pop();
            }
            st.push(x);
        }
        return true;
    }
};
