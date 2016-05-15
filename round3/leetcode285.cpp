
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
    /*iterative version first */
    /*the following code assumes that there is no duplicated values in the BST */
    TreeNode* inorderSuccessor_iterative(TreeNode* root, TreeNode* p) {
        if (!root)
            return NULL;
        //case 1 : if node p has right child
        if (p->right) {
            struct TreeNode * curr = p->right;
            while (curr->left) {
                curr = curr->left;
            } 
            return curr;
        }
        //if p does not have a right child
        else {
            struct TreeNode * found = NULL;
            while (root) {
                if (root->val > p->val) {
                    found = root;
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
            return found;
        }
    }
    //think what about inorder predecessor
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
        if (!root)
            return NULL;
        //if p has left child (or left subtree)
        if (p->left) {
            struct TreeNode * curr = p->left;
            while (curr->right) {
                curr = curr->right;
            }
            return curr;
        }
        else {
            struct TreeNode * found = NULL;
            while (root) {
                if (root->val < p->val) {
                    found = root;
                    root = root->right;
                }
                else
                    root = root->right;
            }
            return found;
        }
    }
    
    //method 2: what about using recursive method ?
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root)
            return NULL;
        if (root->val <= p->val)
            return inorderSuccessor(root->right, p);//need to find inorder successor in its right subtree
        else {
            struct TreeNode * found = inorderSuccessor(root->left, p);
            if (found)
                return found;
            else
                return root;
        }
    }
    
    struct TreeNode * inorderPredecessor_recursive(struct TreeNode * root, struct TreeNode * p) {
        if (!root)
            return NULL;
        if (root->val >= p->val)
            return inorderPredecessor(root->left, p);
        else {
            struct TreeNode * found = inorderPredecessor(root->right, p);
            if (found)  
                return found;
            else    
                return root;
        }
    }
};
