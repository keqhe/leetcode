#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
	//the leetcode way of serialization
    //ref:https://leetcode.com/discuss/73461/short-and-straight-forward-bfs-java-code-with-a-queue
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (!root)
            return res;
        queue<struct TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            struct TreeNode * p = q.front();
            q.pop();
            if (!p)
                res += "n ";
            else 
                res += to_string(p->val) + " ";
            if (p) {
                q.push(p->left);
                q.push(p->right);
            }
        }
        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;
        vector<string> tmp;
        int j = 0;
        for (int i = 0; i < data.length(); i ++) {
            if (data[i] == ' ') {//"123 " or "123 456 " 
                string s = data.substr(j, i-j);
                j = i + 1;
                tmp.push_back(s);
            }
        }
        queue<struct TreeNode*> q;
        struct TreeNode * root = new TreeNode(stoi(tmp[0]));
        q.push(root);
        for (int i = 1; i < tmp.size(); i ++) {
            struct TreeNode * p = q.front();
            q.pop();
            if (tmp[i] != "n") {
                struct TreeNode * l = new TreeNode(stoi(tmp[i]));
                p->left = l; 
                q.push(p->left);
            }
            if (tmp[++i] != "n") {
                struct TreeNode * r = new TreeNode(stoi(tmp[i]));
                p->right = r; 
                q.push(p->right);
            }
        }
        
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

void inorder(struct TreeNode * p) {
	if (!p)
		return;	
	inorder(p->left);
	cout << p->val << ' ';
	inorder(p->right);
}
int main() {
	class Codec test;
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
	string res = test.serialize(p5);
	cout << res << endl;
	struct TreeNode * root = test.deserialize(res);
	cout << "in order traversal of the deserialized binary tree" << endl;
	inorder(root);
	cout << endl;
	return 0; 
}
