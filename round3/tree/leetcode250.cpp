
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
    //first thought, check each node, the time complexity is O(nlogn)
    bool check(struct TreeNode * root) {
        if (!root)
            return true;
        bool a = check(root->left);
        bool b = check(root->right);
        if (a && b) {
            if (!root->left && !root->right)
                return true;
            else if (!root->left)
                return root->val == root->right->val;
            else if (!root->right)
                return root->val == root->left->val;
            else
                return (root->val == root->left->val) && (root->val == root->right->val);
        }
        return false;
    }
    void helper(struct TreeNode * root, int & count) {
        if (!root)
            return;
        if (check(root))
            count ++;
        helper(root->left, count);
        helper(root->right, count);
    }
    int countUnivalSubtrees_method1(TreeNode* root) {
        int count = 0;
        helper(root, count);
        return count;
    }
    
    //method 2, if we do bottom up approach, then the time complexity is O(n)
    bool bottom_up(struct TreeNode * root, int & count) {
        if (!root)
            return true;
        bool a = bottom_up(root->left, count);
        bool b = bottom_up(root->right, count);
        
        if (a && b) {
            if (!root->left && !root->right) {
                count ++;
                return true;
            }
            else if (!root->left) {
                if (root->val == root->right->val) {
                    count ++;
                    return true;
                }
            }
            else if (!root->right) {
                if (root->val == root->left->val) {
                    count ++;
                    return true;
                }
            }
            else {
                if((root->val == root->left->val) && (root->val == root->right->val)) {
                    count ++;
                    return true;
                }
            }
        }
        return false;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        bool res = bottom_up(root, count);
        return count;
    }
};
