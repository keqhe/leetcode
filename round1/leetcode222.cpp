
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
    //good reference: http://blog.csdn.net/kangrydotnet/article/details/46521507
    //navie solution, but a good start, time complexity is O(n)
    int countNodes_naive(TreeNode* root) {
        if (root == NULL)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    //better solution, time complexit is O(1+...h) = O(h^2) = O(logN*logN)
    //also, note that 
    int leftHeight(struct TreeNode * root) {
        int res = 0;
        while (root) {
            res ++;
            root = root->left;
        }
        return res;
    }
    int rightHeight(struct TreeNode * root) {
        int res = 0;
        while (root) {
            res ++;
            root = root->right;
        }
        return res;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = leftHeight(root);
        int right = rightHeight(root);
        if (left == right) {
            return (1 << left) - 1;//faster than pow(2, y)
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
