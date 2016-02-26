#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//WRONG!!,void findPreSuc(struct TreeNode * root, int key, struct TreeNode & * pre, struct TreeNode & * suc) {
void findPreSuc(struct TreeNode * root, int key, struct TreeNode * & pre, struct TreeNode * & suc) {
	if (!root)
		return;
	if (root->val == key) {
		if(root->left) {
			struct TreeNode * tmp = root->left;
			while (tmp->right) {
				tmp = tmp->right;
			}
			pre = tmp;
		}
		if (root->right) {
			struct TreeNode * tmp = root->right;
			while (tmp->left) {
				tmp = tmp->left;
			}
			suc = tmp;
		}
		return; //done
	}
	if (root->val < key) {
		pre = root;
		findPreSuc(root->right, key, pre, suc);
	}
	else {
		suc = root;
		findPreSuc(root->left, key, pre, suc);
	}
}

int main() {
	struct TreeNode *p2 = new TreeNode(2);
	struct TreeNode *p1 = new TreeNode(1);
	struct TreeNode *p3 = new TreeNode(3);
	
	p2->left = p1;
	p2->right = p3;
	struct TreeNode * pre = NULL;
	struct TreeNode * suc = NULL;

	findPreSuc(p2, p2->val, pre, suc);

	cout << pre->val << " " << suc->val << endl;
	delete p1, p2, p3;
	return 0;
}
