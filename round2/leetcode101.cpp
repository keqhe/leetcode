
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
    bool helper(struct TreeNode* l, struct TreeNode* r) {
        if (!l && !r) //all are NULL
            return true;
        else if (!l || !r)//only 1 sub-tree is NULL
            return false;
        else if (l->val != r->val)
            return false;
        else {
            return helper(l->left, r->right) && helper(l->right, r->left);
        }
    }
    bool isSymmetric_idea1(TreeNode* root) {
        if (!root)
            return true;
        return helper(root->left, root->right);
    }
    //another method is BFS, or level-order traversal
    //ref: https://leetcode.com/discuss/79348/iterative-java-solution-with-explanation
    bool isSymmetric(struct TreeNode * root) {
        if (!root)  
            return true;
        queue<struct TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<struct TreeNode*> tmp;
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                struct TreeNode * p = q.front();
                tmp.push_back(p);
                q.pop();
                if (p) {
                    q.push(p->left);
                    q.push(p->right);
                }
            }
            
            int i = 0;
            int j = tmp.size() - 1;
            //cout << i << " " << j << endl;
            while (i < j) {
                if (!tmp[i] && !tmp[j]) {
                    i ++;
                    j --;
                }
                else if (!tmp[i] || !tmp[j])
                    return false;
                else if (tmp[i] && tmp[j]) {
                    if (tmp[i]->val != tmp[j]->val)
                        return false;
                    i ++;
                    j --;
                }
            }
        }
        return true;
    }
};
