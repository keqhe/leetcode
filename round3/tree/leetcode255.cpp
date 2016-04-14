
class Solution {
public:
    //idea: using a stack to do preorder traversal and update curr_low
    //think: curr_low is the root of a subtree, when we meet a large number than the stack's top, we should have finished visiting that subtree
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty())
            return true;
        stack<int> st;
        long curr_low = numeric_limits<long>::min();
        for (int i = 0; i < preorder.size(); i ++) {
            if (preorder[i] < curr_low)
                return false;
            if (st.empty())    
                st.push(preorder[i]);
            else {
                if (preorder[i] < st.top())
                    st.push(preorder[i]);
                else {
                    while (!st.empty() && preorder[i] > st.top()) {
                        curr_low = max(curr_low, (long)st.top());
                        st.pop();
                    }
                    st.push(preorder[i]);
                }
            }
        }
        return true;
    }
};
