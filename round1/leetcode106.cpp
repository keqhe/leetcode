
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
    unordered_map<int, int> m;
    //first think of an example, BST
    //preorder: 3, 2, 1, 4, 5
    //inorder: 1, 2, 3, 4, 5
    //postorder: 1, 2, 5, 4, 3
    
    struct TreeNode* helper(vector<int>& in, int inL, int inR, vector<int>& post, int postL, int postR) {
        if (inL > inR)
            return NULL;
            
        int key = post[postR];
        struct TreeNode * root = new TreeNode(key);
        int index = m[key];//found index in "inorder" array
        
        int lsize = index - inL;
        int rsize = inR - index;
        
        root->left = helper(in, inL, index-1, post, postL, postL+lsize-1);
        root->right = helper(in, index+1, inR, post, postR-rsize, postR-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i ++)
            m[inorder[i]] = i;
        
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
