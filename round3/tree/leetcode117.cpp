
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
    //first thought is level order traversal, but this problem requires O(1) space
    //the problem is essentially level order traversal with O(1) space and the next pointer in node
    void connect(TreeLinkNode *root) {
        struct TreeLinkNode *tmp = new TreeLinkNode(0);
        while (root) {
            
            struct TreeLinkNode * curr = tmp;
            while (root) {
                if (root->left) {
                    curr->next = root->left;//tmp->next may be changed here
                    curr = curr->next;
                }
                if (root->right) {
                    curr->next = root->right;//tmp->next may also be changed here
                    curr = curr->next;
                }
                root = root->next;
            }
            //explore the next level
            root = tmp->next;
            tmp->next = NULL;//otherwise, in case there is no next level, the program won't stop
        }
    }
};
