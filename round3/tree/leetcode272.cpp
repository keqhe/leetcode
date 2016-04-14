
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
    //idea: deque and inorder traversal
    //time complexity is O(n)
    void inorder(struct TreeNode* root, deque<int> & de, double target, int k) {
        if (!root)
            return;
        inorder(root->left, de, target, k);
        if (de.size() < k)
            de.push_back(root->val);
        else {
            int front = de.front();
            double diff_front = abs((double)front - target);
            double diff_curr = abs((double)root->val - target);
            if (diff_front > diff_curr) {
                de.pop_front();
                de.push_back(root->val);
            }
        }
        inorder(root->right, de, target, k);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> de;
        inorder(root, de, target, k);
        vector<int> res;
        while (!de.empty()) {
            res.push_back(de.front());
            de.pop_front();
        }
        return res;
    }
};
