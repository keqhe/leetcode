#include<iostream>
#include<string>
#include<vector>
#include<limits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int global_max = numeric_limits<int>::min();
    int helper(struct TreeNode * root) {
        if (!root)
            return 0;
        int a = helper(root->right);
        int b = helper(root->left);
        
        if (!root->left && !root->right) {
            global_max = max(global_max, root->val);
            return root->val;
        }
        else if (!root->left) {
            //global_max = max(global_max, root->val+a);//WRONG
            global_max = max(global_max, max(root->val+a, root->val));
            //return root->val + a;//WRONG
            return max(root->val, root->val + a);
        }
        else if (!root->right) {
            global_max = max(global_max, max(root->val+b, root->val));
            return max(root->val, root->val + b);
        }
        else {
            global_max = max(global_max, max(root->val+a+b, max(root->val+a, max(root->val+b, root->val))));;
            // return max(root->val+a+b, max(root->val+a, max(root->val+b, root->val)));//WRONG, think why
            return max(root->val+a, max(root->val+b, root->val));
        }
        
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        helper(root);
        return global_max;
    }
};

int main() {
	class Solution sn;
	return 0;
}
