#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
        int val;
        struct TreeNode * left;
        struct TreeNode * right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        queue<struct TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<struct TreeNode*> level;
            //cout << "queue size is : " << q.size() << endl;
            //for (int i = 0; i < q.size(); i ++) {//this is WRONG, think why? :)
            while (!q.empty()) {
                struct TreeNode * p = q.front();
                q.pop();
                //cout << p->val << " ";
                level.push_back(p);
            }
            //cout << endl;
            //cout << "queue size now is : " << q.size() << endl << endl;
            
            if (!level.empty()) {
                res.push_back(level.back()->val);
            }
            
            for (int i = 0; i < level.size(); i ++) {
                struct TreeNode * p = level[i];
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
        }
        
        return res;
    }
};

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

	class Solution sn;
	vector<int> res = sn.rightSideView(p5);
	for (auto x : res)
		cout << x << " ";
	cout << endl;
	return 0;
}
