
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
    //first thought is level order traversal, but this method is not constant space
    void connect(TreeLinkNode *root) {
        while (root && root->left) {//still has the next level
            struct TreeLinkNode * p = root;
            while (p) {//p must has both left and right child
                p->left->next = p->right;
                if (p->next)
                    p->right->next = p->next->left;
                p = p->next;
            }
            root = root->left;
        }
    }
};
