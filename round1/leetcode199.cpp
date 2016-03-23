
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        helper(root, 0, res);
        return res;
    }
    
    void helper(struct TreeNode * root, int level, vector<int> & nums) {
        if (!root)
            return;
        if (nums.size() == level)
            nums.push_back(root->val);
        helper(root->right, level + 1, nums);
        helper(root->left, level + 1, nums);
    }
    //level search, BFS version
    vector<int> rightSideView2(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        queue<vector<struct TreeNode*>> q;
        vector<struct TreeNode*> start;
        start.push_back(root);
        q.push(start);
        
        while(!q.empty()) {
            vector<struct TreeNode*> curr = q.front();
            q.pop();
            
            vector<struct TreeNode*> next;
            for (int i = 0; i < curr.size(); i ++) {
                if (curr[i]->left)
                    next.push_back(curr[i]->left);
                if (curr[i]->right)
                    next.push_back(curr[i]->right);
                    
                if (i == curr.size() - 1) {
                    res.push_back(curr[i]->val);
                }
            }
            
            if (next.size() > 0)
                q.push(next);
        }
        return res;
    }
};
