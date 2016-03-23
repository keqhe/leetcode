
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
    //recrusive, divide and conquer, cache (unordered_map, hashmap)
    //reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-unique-binary-search-trees-i-ii.html
    //coding style similar to https://leetcode.com/problems/different-ways-to-add-parentheses/
    //
    vector<struct TreeNode*> helper(int Min, int Max, unordered_map<string,vector<struct TreeNode*>> & m) {
        string str1 = to_string(Min);
        string str2 = to_string(Max);
        string key = str1 + "-" + str2;
        if (m.find(key) != m.end())
            return m[key];
        vector<struct TreeNode*> res;
        if (Min > Max) {
            res.push_back(NULL);
            return res;
        }
        else {
            for (int i = Min; i <= Max; i ++) {
                vector<struct TreeNode*> lefts = helper(Min, i-1, m);
                vector<struct TreeNode*> rights = helper(i+1, Max, m);
                
                for (auto l : lefts) {
                    for (auto r : rights) {
                        struct TreeNode * root = NULL;
                        root = new TreeNode(i);
                        root->left = l;
                        root->right = r;
                        res.push_back(root);
                    }
                }
            }
        }
        m[key] = res;
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<struct TreeNode*> res;
        if (n == 0)
            return res;
        unordered_map<string, vector<struct TreeNode*>> m;
        return helper(1, n, m);
    }
};
