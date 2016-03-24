
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
    //first think about using a deque, 
    //similar idea as https://leetcode.com/discuss/64537/inorder-traversal-with-deque-to-maintain-result-time-space
    //just think about this: how to get the predecessor and successor of a node in BST?
    //see: http://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
    deque<int> de;
    bool found = false;
    void inorder(struct TreeNode * root, double target, int k, vector<int> & res) {
        if (!root)
            return;
        inorder(root->left, target, k, res);
        if (de.size() < k) {
            de.push_back(root->val);
        }
        else {
            int smallest = de.front();
            int largest = de.back();
            if (abs(target-smallest) > abs(root->val - target)) {
                de.pop_front();
                de.push_back(root->val);
            }
            else {//found
                //found
                //cout << "found..." << endl;
                if (!found) {
                    found = true;
                    for (deque<int>::iterator it = de.begin(); it != de.end(); it ++) {
                        res.push_back(*it);
                    }
                }
            }
        }
        inorder(root->right, target, k, res);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        if (k == 0)
            return res;
        inorder(root, target, k, res);
        if (!found) {
            found = true;
            for (deque<int>::iterator it = de.begin(); it != de.end(); it ++) {
                res.push_back(*it);
            }
        }
        return res;
            
    }
};
