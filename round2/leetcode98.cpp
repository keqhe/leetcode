
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
    /* this following is wrong idea
    bool helper(struct TreeNode * root) {
        if (!root)
            return true;
        if (root->left && root->right) {
            return root->left->val < root->val && root->right->val > root->val && helper(root->left) && helper(root->right);
        }
        else if (root->left && !root->right) {
            return root->left->val < root->val && helper(root->left);
        }
        else if (!root->left && root->right) {
            return root->right->val > root->val && helper(root->right);
        }
        else 
            return true;
    }*/
    //in order traversal, iterative
    bool isValidBST_iterative(TreeNode* root) {
        stack<struct TreeNode*> st;
        //int last = numeric_limits<int>::min();
        long last = numeric_limits<long>::min();
        while (!st.empty() || root) {
            if (root) {
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
                //if (root->val < last) //wrong for test case [1, 1]
                if (root->val <= last)
                    return false;
                last = (long) root->val;
                root = root->right;
            }
        }
        return true;
    }
    bool recursive_helper(struct TreeNode * root, long min_val, long max_val) {
        if (!root)
            return true;
        if (root->val >= max_val || root->val <= min_val)
            return false;
        return recursive_helper(root->left, min_val, root->val) && 
            recursive_helper(root->right, root->val, max_val);
    }
    bool isValidBST(TreeNode* root) {
        return recursive_helper(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
};
