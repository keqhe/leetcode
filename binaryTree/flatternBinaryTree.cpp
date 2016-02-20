#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;	
	struct TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //ref: https://leetcode.com/discuss/81419/clean-java-1ms-recursive-solution
    //ref: https://leetcode.com/discuss/81419/clean-java-1ms-recursive-solution
    struct TreeNode * helper(struct TreeNode * root) {
        if (!root->left && !root->right)
            return root;
        if (root->right)
            return helper(root->right);
        else
            return helper(root->left);
    }
    void flatten(TreeNode* root) {
        if (!root)
            return;
        if (root->left) {
            //flatten the left sub-tree
            flatten(root->left);
            //get the last in the left subtree
            struct TreeNode * left_last = helper(root->left);
            //set the right of left_last to root->right
            left_last->right = root->right;
            //flatten root->right
            flatten(root->right);
            root->right = root->left;
            root->left = NULL;
        }
        else {
            flatten(root->right);
        }
        
    }
};

void inorder(struct TreeNode * p) {
        if (!p)
                return;
        inorder(p->left);
        cout << p->val << ' ';
        inorder(p->right);
}


int main() {
	struct TreeNode * p5 = new TreeNode(5);
        struct TreeNode * p2 = new TreeNode(2);
        struct TreeNode * p1 = new TreeNode(1);
        struct TreeNode * p7 = new TreeNode(7);
        struct TreeNode * p6 = new TreeNode(6);
        struct TreeNode * p8 = new TreeNode(8);

        p5->left = p2;
        p2->left = p1;
        p5->right = p7;
        p7->left = p6;
        p7->right = p8;

        cout << "in order traversal of the orginal binary tree" << endl;
        inorder(p5);
        cout << endl;

	class Solution sn;
	sn.flatten(p5);
	
	cout << "in order traversal of the flattened binary tree" << endl;
        inorder(p5);
        cout << endl;

	return 0;	
}
