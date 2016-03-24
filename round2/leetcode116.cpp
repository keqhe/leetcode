
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
    //level order traversal can solve this problem ,but not constant space
    //ref: https://leetcode.com/discuss/87477/share-my-loop-java-1ms-solution-easy-understand
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        while (root->left) {
            struct TreeLinkNode * p = root;
            while (p) {
                p->left->next = p->right;
                if (p->next) p->right->next = p->next->left;
                p = p->next;
            }
            root = root->left;
        }
    }
};
