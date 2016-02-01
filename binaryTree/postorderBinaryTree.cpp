#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode (int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

class Solution {
public:
    //preorder and inorder traversal is considered medium
    //poster order traveral is hard (interative version)
    //      6
    //  3       8
    //1   4   7   9
    //post order is : [1, 4, 3, 7, 9, 8, 6]
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        list<int> l;//becuase list's push_front has low overhead compared with vector
        stack<struct TreeNode*> st;
        while (!st.empty() || root) {
            if (root) {
                l.push_front(root->val);//post order
                st.push(root);
                root = root->right;//post order
            }
            else {
                root = st.top();
                st.pop();
                root = root->left;//post order
            }
        }
        //for (auto it = l.crbegin(); it != l.crend(); it ++)
        for (auto it = l.begin(); it != l.end(); it ++)
            res.push_back(*it);
        return res;
    }
};

int main() {
	class Solution sn;
	struct TreeNode *p1 = new TreeNode(1);
	struct TreeNode *p2 = new TreeNode(2);
	struct TreeNode *p3 = new TreeNode(3);

	p2->left = p1;
	p2->right = p3;
	vector<int> res = sn.postorderTraversal(p2);
	for (auto & x : res)
		cout << x << " ";
	cout << endl;
	return 0;
}
