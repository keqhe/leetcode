
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
    //there is a level order traversal solution
    //ref: https://leetcode.com/discuss/58413/simple-java-solution-using-level-order-traversal
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return NULL;
        queue<struct TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            struct TreeNode * p = q.front();
            q.pop();
            struct TreeNode * l = p->left;
            struct TreeNode * r = p->right;
            
            if (p->right) {
                q.push(p->right);
            }
            if (p->left)
                q.push(p->left);
            p->left = r;
            p->right = l;
        }
        
        return root;
    }
    //this is pre order process
    TreeNode* invertTree_way2(TreeNode* root) {
        if (!root)
            return NULL;
        struct TreeNode * temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
    
    //below is bottom up, or i would think as post order process of binary tree
    TreeNode* invertTree_way1(TreeNode* root) {
        if (!root)
            return NULL;
        //comment this below as works
        /*if (!root->left && !root->right)
            return root;
        */
        struct TreeNode * a = invertTree(root->left);
        struct TreeNode * b = invertTree(root->right);
        root->left = b;
        root->right = a;
        return root;
    }
};
