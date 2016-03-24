
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
    
    //preorder based method, passed all test cases
    /*
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
    */
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
