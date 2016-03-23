
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
    //{3,9,20,#,#,15,7}
    //{3,9,20,#,#,15,7,#,#,#,#}
    //left = 2i + 1, right = 2i + 2
    //{3,9,20,#,#,15,7,#,#,8,6,#,#,#,#}
    //
    //{2,1,3,#,#,#,#}
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<struct TreeNode*> q;
        vector<vector<int>> v;
        vector<vector<int>> res;
        
        if (!root)
            return res;
        q.push(root);
        while(!q.empty()) {
            vector<struct TreeNode*> temp;
            vector<int> tempVal;
            while(!q.empty()) {
                struct TreeNode * curr = q.front();
                q.pop();
                temp.push_back(curr);
                tempVal.push_back(curr->val);
            }
            //add one level result
            v.push_back(tempVal);
            //put next level into queue
            for (int i = 0; i < temp.size(); i ++) {
                struct TreeNode * p = temp[i];
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
        }
        for (int i = v.size() - 1; i >=0; i --) {
            res.push_back(v[i]);
        }   
        
        return res;
    }
};
