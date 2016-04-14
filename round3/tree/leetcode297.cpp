
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
    //preorder traversal on binary tree is a good method to solve this serialization and deserilization problem, note that NULL should be encoded as well
    /*
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
    */
    //method 2, what about using level order traversal, ie, the serilization method OJ uses
    // Encodes a tree to a single string.
    string level_order_encode(struct TreeNode * root) {
        string res;
        if (!root) {
            res += "#,";
            return res;   
        }
        queue<struct TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                struct TreeNode * curr = q.front();
                q.pop();
                if (!curr)
                    res += "#,";
                else
                    res += to_string(curr->val) + ",";
                if (curr) {
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        if (!res.empty())
            res.pop_back();
        return res;
    }
    string serialize(TreeNode* root) {
        return level_order_encode(root);
    }
    struct TreeNode * level_order_decode(string s) {
        int i = 0;
        size_t stop = s.find(",", i);
        string str = s.substr(i, stop-i);
        i = stop + 1;
        struct TreeNode * root = NULL;
        if (str != "#") {
            root = new TreeNode(stoi(str));
        }
        else
            return NULL;
        queue<struct TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int j = 0; j < size; j ++) {
                struct TreeNode * curr = q.front();
                q.pop();
                if (curr) {
                    //left child
                    stop = s.find(",", i);
                    str = s.substr(i, stop-i);
                    if (str != "#") {
                        curr->left = new TreeNode(stoi(str));
                        
                    }
                    q.push(curr->left);
                    i = stop + 1;
                    //right child
                    stop = s.find(",", i);
                    str = s.substr(i, stop-i);
                    if (str != "#") {
                        curr->right = new TreeNode(stoi(str));
                        
                    }
                    q.push(curr->right);
                    i = stop + 1;
                }
            }
        }
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return level_order_decode(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
