
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
    void encode_preorder(struct TreeNode * root, string &res) {
        if (!root) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ",";
        encode_preorder(root->left, res);
        encode_preorder(root->right, res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        encode_preorder(root, res);
        if (!res.empty())
            res.pop_back();//the last ","
        cout << res << endl;
        return res;
    }
    struct TreeNode* decode_preorder(string s, int & index) {
        if (s.length() <= index)
            return NULL;
        size_t stop = s.find(",", index);
        string str_num = s.substr(index, stop-index);//think about "123,"
        
        struct TreeNode * root = NULL;
        if (str_num == "#") {
            index = stop+1;
        }
        else {
            root = new TreeNode(stoi(str_num));
            index = stop + 1;
            root->left = decode_preorder(s, index);
            root->right = decode_preorder(s, index);
        }
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return decode_preorder(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
