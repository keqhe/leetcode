
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    //idea stack, similar to inorder traversal
    stack<struct TreeNode* > st;
    BSTIterator(TreeNode *root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!st.empty());
    }

    /** @return the next smallest number */
    int next() {
        struct TreeNode * p = st.top();
        st.pop();
        int a = p->val;
        p = p->right;
        while (p) {
            st.push(p);
            p = p->left;
        }
        
        return a;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
