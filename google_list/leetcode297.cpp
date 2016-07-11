
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
    void helper1(TreeNode* root, string &res) {
        if (!root) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ",";
        helper1(root->left, res);
        helper1(root->right, res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        helper1(root, res);
        return res;
    }
    //both helper2 and helper3 works
    TreeNode * helper2(string s, int & index) {
        if (s.length() <= index)
            return NULL;
        
        int pos = s.find(',', index);
        string curr = s.substr(index, pos-index);
        TreeNode * root = nullptr;
        if (curr == "#") {
            index = pos + 1;
        }
        else {
            index = pos+1;
            int val = stoi(curr);
            root = new TreeNode(val);
            root->left = helper2(s, index);
            root->right = helper2(s, index);
        }
        return root;
    }
    
    TreeNode * helper3(string s, int & index) {
        if (s.length() <= index)
            return NULL;
        if (s.front() == '#') {
            index += 2;
            return nullptr;
        }
        int pos = s.find(',', index);
        string curr = s.substr(index, pos-index);
        TreeNode * root = nullptr;
        
        index = pos+1;
        int val = stoi(curr);
        root = new TreeNode(val);
        root->left = helper2(s, index);
        root->right = helper2(s, index);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return helper3(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
