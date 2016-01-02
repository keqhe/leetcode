#include<iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode() {
		left = NULL;
		right = NULL;
	}
	TreeNode(int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};
class easyBST {
public:
	struct TreeNode * tree_root = NULL;
	easyBST() {
		tree_root = NULL;
	}
	easyBST(int x) {
		tree_root = new TreeNode(x);
	}
	void destory(struct TreeNode * root) {
		if (!root)
			return;
		destory(root->left);
		destory(root->right);
		delete root;
	}
	~easyBST() {
		destory(tree_root);
	}
	void insert(struct TreeNode * & root, int x) {
		if (!root) {
			root = new TreeNode(x);
			return;
		}
		if (x < root->val) {
			insert(root->left, x);
		}
		else if (x > root->val) {
			insert(root->right, x);
		}
	}
	//find the minimal node in its right subtree
	struct TreeNode * findMinRight(struct TreeNode * root) {
		if (!root)
			return NULL;
		while (root->left) {
			root = root->left;
		}
		return root;
	}
	struct TreeNode * __remove(struct TreeNode * root, int x) {
		if (!root)
			return NULL;
		if (x < root->val)
			return __remove(root->left, x);
		else if (x > root->val)
			return __remove(root->right, x);
		else {
			//case 1, no child
			if (!root->left && !root->right) {
				delete root;
				root = NULL;
			}
			//case 2, 1 child	
			else if (!root->left) {
				struct TreeNode * temp = root;
				root = root->right;
				delete temp;
			}
			//still case 2
			else if (!root->right) {
				struct TreeNode * temp = root;
				root = root->left;
				delete temp;
			}
			//case 3, 2 children
			else {
				struct TreeNode *t = findMinRight(root->right);
				root->val = t->val;
				root->right = __remove(root->right, x);
			}
			return root;
		}
	}
};
class Solution {
public:
    //reference: https://leetcode.com/discuss/74359/4-line-c-simple-solution-easy-understanding
    //is it recursive or DFS? recursive is DFS, right?
    bool helper(struct TreeNode * root, long low, long high) {
        if (!root)
            return true;
        return (low < root->val) && (root->val < high) && helper(root->left, low, root->val) && 
        helper(root->right, root->val, high);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
};

int main() {
	class easyBST bst(2);
	class Solution sn;
	bst.insert(bst.tree_root, 1);
	bst.insert(bst.tree_root, 3);
	cout <<	sn.isValidBST(bst.tree_root) << endl;
	return 0;
}
