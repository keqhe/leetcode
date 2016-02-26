#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root)
            return NULL;
        if (!root->left && !root->right)
            return root;
        struct TreeNode* leftRoot = upsideDownBinaryTree(root->left);
        struct TreeNode * p = leftRoot;
        while (p->right) {
            p = p->right;
        }
        p->left = root->right;
        p->right = root;
        root->right = NULL;
        root->left = NULL;
        
        return leftRoot;
    }
};

int main() {
	class Solution sn;
	return 0;
}
