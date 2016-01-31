#include<iostream>
#include<string>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {};
};

//iterative solution and recursive soltion. Similar ideas can be applied to get predecessor for BST node
class Solution {
public:
    //   3
    // 1   5
    //    4
    //iterative version
    TreeNode* inorderSuccessor_iterative(TreeNode* root, TreeNode* p) {
        if (!root || !p)    
            return NULL;
        //case 1, p has right child
        if (p->right) {
            p = p->right;
            while (p->left) {
                p = p->left;
            }
            return p;
        }
        //case 2, if p does not have right child
        else {
            struct TreeNode * found = NULL;
            while (root) {
                if (root->val > p->val) {
                    found = root;
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
            return found;
        }
        
    }
    //   3
    // 1   5
    //    4
     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root)
            return NULL;
        if (root->val <= p->val)
            return inorderSuccessor(root->right, p);
        else {
            struct TreeNode * left = inorderSuccessor(root->left, p);
            if (left)
                return left;
            else
                return root;
        }
     }
};

int main() {
	class Solution sn;
	struct TreeNode * r = new TreeNode(1);
	struct TreeNode * s = sn.inorderSuccessor(r, r);
	return 0;
}
