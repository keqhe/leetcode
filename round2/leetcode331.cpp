
class Solution {
public:
    /* google interview problem
    ref: https://www.hrwhisper.me/leetcode-verify-preorder-serialization-of-a-binary-tree/
    这个方法简单的说就是不断的砍掉叶子节点。最后看看能不能全部砍掉。
已例子一为例，：”9,3,4,#,#,1,#,#,2,#,6,#,#” 遇到x # #的时候，就把它变为 #
我模拟一遍过程：

    9,3,4,#,# => 9,3,# 继续读
    9,3,#,1,#,# => 9,3,#,# => 9,# 继续读
    9,#2,#,6,#,# => 9,#,2,#,# => 9,#,# => #

合法的情况最后一定是一个#
    */
    bool isValidSerialization(string preorder) {
        if (preorder.empty())
            return false;
        int len = preorder.length();
        vector<string> tmp;
        int start = 0;
        stack<string> st;
        for (int i = 0; i < len; i ++) {
            if (preorder[i] == ',') {
                string str = preorder.substr(start, i-start);
                tmp.push_back(str);
                start = i + 1;
            }
            if (i == len-1) {
                string str = preorder.substr(start, i-start+1);
                tmp.push_back(str);
            }
        }
        for (auto x : tmp) {
            if (x == "#") {
                //if (!st.empty() && st.top() == "#") { //WRONG
                while (!st.empty() && st.top() == "#") {
                    st.pop();//pop left child
                    if (st.empty())
                        return false;
                    st.pop();//pop the leaf number
                }
            }
            st.push(x);
        }
        
        return st.size() == 1 && st.top() == "#";
    }
};
