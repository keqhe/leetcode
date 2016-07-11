
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // the following code has time complexity of O(n)
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        if (!root || k == 0)
            return res;
        deque<int> de;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
                int value = root->val;
                if (de.empty())
                    de.push_back(value);
                else {
                    double diff1 = abs((double)value-target);
                    double diff2 = abs((double)de.front()-target);
                    if (de.size() < k) {
                        de.push_back(value);
                    }
                    else {
                        if (diff1 < diff2) {
                            de.pop_front();
                            de.push_back(value);
                        }
                        else {
                            break;
                        }
                    }
                }
                root = root->right;
            }
        }
        while (!de.empty()) {
            res.push_back(de.front());
            de.pop_front();
        }
        return res;
    }
};
