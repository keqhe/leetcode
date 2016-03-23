
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(struct TreeNode* root, string & res) {
        if (!root) {
            res += "# ";
            return;
        }
        else {
            res += to_string(root->val) + " ";
            preorder(root->left, res);
            preorder(root->right, res);
        }
    }
    string serialize(TreeNode* root) {
        string res;
        if (!root)
            return res;
        preorder(root, res);
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    struct TreeNode * decode(string & data, int & index) {
        if (index > data.length() - 1)
            return NULL;
        int i;
        for (i = index; i < data.length(); i ++) {
            if (data[i] == ' ')
                break;
        }
        string str = data.substr(index, i-index);
        if (str == "#") {
            index = i + 1;
            return NULL;
        }
        
        int val = stoi(str);
        struct TreeNode * root = NULL;
        root = new TreeNode(val);
        index = i + 1;

        if (root) {
                root->left = decode(data, index);
                root->right = decode(data, index);
        }
        
        return root;
    }
    TreeNode* deserialize(string data) {
        if (data.length() == 0)
            return NULL;
        int index = 0;
        struct TreeNode * root = decode(data, index);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
