
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
    //the naive solution (which takes O(n) space as noted) is to use a array to store all the elements by inorder BST trversal, the resulted array should be sorted if there is no such mistake.
    //so we can indentify which two nodes are swapped
    
    //the hard part is can we find a solution which uses constant space?
    struct TreeNode * n1 = NULL;
    struct TreeNode * n2 = NULL;
    void inorder(struct TreeNode * root, struct TreeNode *& prev) {
        if (!root)
            return;
        inorder(root->left, prev);
        //cout << root->val << endl;
        if (prev != NULL && prev->val > root->val) {
            if (!n1) //this is the first time we encounter swapped node
                n1 = prev;
            n2 = root;
        }
        prev = root;
        inorder(root->right, prev);
        
    }
    void recoverTree(TreeNode* root) {
        struct TreeNode * prev = NULL;
        inorder(root, prev);
        int tmp;
        tmp = n1->val;
        n1->val = n2->val;
        n2->val = tmp;
    }
};
