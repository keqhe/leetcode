
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
        queue<struct TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<struct TreeNode*> level;
            //cout << "queue size is : " << q.size() << endl;
            //for (int i = 0; i < q.size(); i ++) {//this is WRONG, think why? :)
            while (!q.empty()) {
                struct TreeNode * p = q.front();
                q.pop();
                //cout << p->val << " ";
                level.push_back(p);
            }
            //cout << endl;
            //cout << "queue size now is : " << q.size() << endl << endl;
            
            if (!level.empty()) {
                res.push_back(level.back()->val);
            }
            
            for (int i = 0; i < level.size(); i ++) {
                struct TreeNode * p = level[i];
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
        }
        
        return res;
    }
};
