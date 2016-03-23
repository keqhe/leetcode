
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
    //ref: https://leetcode.com/discuss/73410/easy-understand-java-solution-with-bfs-treemap
    //idea; bfs + map
    map<int, vector<int>> m2;
    //this is DFS, does not meet all of the requirements, for the nodes that have the same position
    /*
    void preorder(struct TreeNode * root, int pos) {
        if (!root)
            return;
        m2[pos].push_back(root->val);
        preorder(root->left, pos - 1);
        preorder(root->right, pos + 1);
    }*/
    
    void bfs(struct TreeNode * root) {
        if (!root)
            return;
        queue<pair<struct TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<struct TreeNode*, int> curr = q.front();
            q.pop();
            struct TreeNode * p = curr.first;
            int col = curr.second;
            m2[col].push_back(p->val);
            
            if (p->left) {
                q.push(make_pair(p->left, col-1));
            }
            if (p->right) {
                q.push(make_pair(p->right, col+1));
            }
        }
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        bfs(root);
        
        vector<vector<int>> res;
        for (auto & x : m2) {
            res.push_back(x.second);
        }
        return res;
    }
};
