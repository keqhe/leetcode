
class Solution {
public:
    //using an extra stack, idea, go through the arrary, push the number into stack if it is small; if it is larger, that means we are in the right trees now and we need to pop all numbers that are smaller than the current number. We need to keep track of lower_bound, if current number < lower_bound, then it is not a valid preorder traversal
    //lower_bound should be the value of the  root of a sub-tree
    //think about
    //     3
    //   2   6
    // 0    4  7
    //[3, 2, 0, 6, 4, 7]
    bool verifyPreorder_space(vector<int>& preorder) {
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
    //how to get O(1) space?
    //reuse preorder array
    bool verifyPreorder(vector<int>& preorder) {
        int i = -1;
        int low = numeric_limits<int>::min();
        for (auto & x : preorder) {
            if (x < low)
                return false;
            while (i >= 0 && preorder[i] < x) {
                low = preorder[i--];
            }
            preorder[++i] = x;
        }
        return true;
    }
};
