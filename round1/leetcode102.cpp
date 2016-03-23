
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
    //update on Nov 25, 2015. VMware internview asked this question, just want to repeat this
    vector<vector<int>> levelOrder(struct TreeNode * root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<struct TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            vector<struct TreeNode*> nodes;
            while(!q.empty()) {//get all the nodes in this level
                struct TreeNode * p = q.front();
                level.push_back(p->val);
                nodes.push_back(p);
                q.pop();
            }
            res.push_back(level);
            for (int i = 0; i < nodes.size(); i ++) {
                if (nodes[i]->left)
                    q.push(nodes[i]->left);
                if (nodes[i]->right)
                    q.push(nodes[i]->right);
            }
        }
        return res;
    }
    //
    vector<vector<int>> levelOrder_mine(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<struct TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            //get one level
            vector<int> tempVal;
            vector<struct TreeNode*> temp;
            while(!q.empty()) {
                struct TreeNode * p = q.front();
                q.pop();
                tempVal.push_back(p->val);
                temp.push_back(p);
            }
            //add one level result
            res.push_back(tempVal);
            //add next level
            for (int i = 0; i < temp.size(); i ++) {
                struct TreeNode * p = temp[i];
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
        }
        return res;
    }
};
