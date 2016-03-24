
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    //best ref: https://leetcode.com/discuss/24398/simple-solution-using-constant-space
    //level order traversal
    void connect(TreeLinkNode *root) {
        struct TreeLinkNode * tempChild = new TreeLinkNode(0);
        while (root) {
            struct TreeLinkNode * curr = tempChild;
            while (root) {
                if (root->left) {
                    curr->next = root->left;
                    curr = curr->next;
                }
                if (root->right) {
                    curr->next = root->right;
                    curr = curr->next;
                }
                root = root->next;
            }
            //next level
            root = tempChild->next;
            tempChild->next = NULL;//needed because it means whether we have next level
        }
    }
};
