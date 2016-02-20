#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    void coder_helper(struct TreeNode * root, string & res) {
        if (!root) {
            res += '#';
            return;
        }
        res += to_string(root->val) + ',';
        coder_helper(root->left, res);
        coder_helper(root->right, res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        coder_helper(root, res);
        cout << res << endl;
        return res;
    }
    
    struct TreeNode * decoder_helper(string data, int & index) {
        if (index >= data.length() || data.empty())
            return NULL;
        if (data[index] == '#') {
            index ++;
            return NULL;
        }
        std::size_t end = data.find(",", index+1);
        int value = 0;
        if (end != string::npos) {
            value = stoi(data.substr(index, end-index));//123,
        }
        struct TreeNode* r = new TreeNode(value);
        index = end + 1;
        r->left = decoder_helper(data, index);
        r->right = decoder_helper(data, index);
        return r;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return decoder_helper(data, index);
    }

    //this is my first version, idea is inorder, it is wrong because not all node->val is 1 digit
    /*
    //"12##34##5##"
    void helper1(struct TreeNode * root, string & res) {
        if (!root) {
            res += '#';
            return;
        }
        res += (char)(root->val + '0');
        helper1(root->left, res);
        helper1(root->right, res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        helper1(root, res);
        cout << res << endl;
        return res;
    }

    struct TreeNode * helper2(string data, int & index) {
        if (index >= data.length() || data.empty())
            return NULL;
        if (data[index] == '#') {
            index ++;
            return NULL;
        }
        struct TreeNode* r = new TreeNode(data[index]-'0');
        index ++;
        r->left = helper2(data, index);
        r->right = helper2(data, index);
        return r;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return helper2(data, index);
    }
    */
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
