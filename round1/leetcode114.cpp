
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

    //O(n) time complexity and O(1) space
    //reference, http://bangbingsyb.blogspot.com/2014/11/leetcode-flatten-binary-tree-to-linked.html
    struct TreeNode* helper(struct TreeNode * root) {
        if (!root)
            return NULL;
        struct TreeNode * lefttail = helper(root->left);
        struct TreeNode * righttail = helper(root->right);
        
        if (root->left) {
            struct TreeNode * temp = root->right;
            root->right = root->left;
            lefttail->right = temp;
            root->left = NULL;
        }
        
        if (righttail)
            return righttail;
        if (lefttail)
            return lefttail;
        return root;
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
    //O(n) time complexity and O(n) space version
    void preorder(struct TreeNode * root, vector<struct TreeNode*> & res) {
        if (!root)
            return;
        res.push_back(root);
        if (root->left)
            preorder(root->left, res);
        if (root->right)
            preorder(root->right, res);
    }
    
    void flatten2(TreeNode* root) {
        if (!root)
            return;
        vector<struct TreeNode*> res;
        preorder(root, res);
        
        struct TreeNode * curr = NULL;
        struct TreeNode * next = NULL;
        for(int i = 0; i < res.size() - 1; i ++) {
            curr = res[i];
            next = res[i+1];
            curr->left = NULL;
            curr->right = next;
        }
        
        if (next) {
            next->left = NULL;
            next->right = NULL;
        }
    }
};
