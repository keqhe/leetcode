
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
    //think, from a memory allocation view, what's the difference using a cache and w/o a cache?
    //will some subtree be reused ?
    //this method is called memorization (top down approach)
    unordered_map<string, vector<struct TreeNode*>> m;
    vector<struct TreeNode*> helper(int left, int right) {
        string key = to_string(left) + "-" + to_string(right);
        if (m.find(key) != m.end())
            return m[key];
        vector<struct TreeNode*> res;
        if (left > right) {
            res.push_back(NULL);
            return res;
        }
        if (left == right) {
            struct TreeNode * root = new TreeNode(left);
            res.push_back(root);
            return res;
        }
        for (int i = left; i <= right; i ++) {
             vector<struct TreeNode*> lefts = helper(left, i-1);
             vector<struct TreeNode*> rights = helper(i+1, right);
             for (auto l : lefts) {
                 for (auto r : rights) {
                     struct TreeNode * root = new TreeNode(i);//it must appear here, think why
                     root->left = l;
                     root->right = r;
                     res.push_back(root);
                 }
             }
        }
        m[key] = res;
        return res;
    }
    vector<TreeNode*> generateTrees_memorization(int n) {
        vector<struct TreeNode*> res;
        if (n <= 0)
            return res;
        return helper(1, n);
    }
    //now think about the second solution, dp, bottom up
    //ref: https://leetcode.com/discuss/31127/a-simple-bottom-up-dp-solution
    vector<TreeNode*> generateTrees(int n) {
        vector<struct TreeNode*> res;
        if (n <= 0)
            return res;
        vector<vector<vector<struct TreeNode*>>> 
            dp(n+2, vector<vector<struct TreeNode*>>(n+2, vector<struct TreeNode*>()));
        
        for (int i = 1; i <= n+1; i ++) {
            dp[i][i].push_back(new TreeNode(i));
            dp[i][i-1].push_back(NULL);
        }
        cout << "debug " << endl;
        for (int gap = 1; gap <= n-1; gap ++) {
            for (int i = 1; i < n; i ++) {//left edge
                //for (int j = i+gap; j <= n; j ++) {//right edge, think why this WRONG
                int j = i + gap;//right edge
                    for (int k = i; j <= n && k <= j; k ++) {//k should be root
                        vector<struct TreeNode*> lefts = dp[i][k-1];
                        vector<struct TreeNode*> rights = dp[k+1][j];
                        for (auto l : lefts) {
                            for (auto r : rights) {
                                struct TreeNode * root = new TreeNode(k);
                                root->left = l;
                                root->right = r;
                                dp[i][j].push_back(root);
                            }
                        }
                    }
            }
        }
        return dp[1][n];
    }
};
