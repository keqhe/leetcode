
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//note, still puzzled about the LCA in binary tree (got better understanding after thinking about it, i think 
//now I have a better understand about post-order and bottom up)
//I made a mistake on C++ string insert string, 
//to insert char, we can use both string::iterator or int pos
//but, to insert string into a string, we have to use int pos.

//post order, bottom up
    vector<string> binaryTreePaths2(TreeNode* root) {
        vector<string> v;
        if (!root)
            return v;
        if (root && root->left == NULL && root->right == NULL) {//bottom is the leaf 
            vector<string> v1;
            string s = to_string(root->val);
            v1.push_back(s);
            return v1;
            
        }
        //root is not leaf if logic reach here  
        vector<string> vleft;
        vector<string> vright;
        if (root->left) {
            vleft = binaryTreePaths(root->left); //c++, vector = operator, this is not trival
        }
        if (root->right) {
            vright = binaryTreePaths(root->right);
        }
        
        for (int i = 0; i < vleft.size(); i ++) {
            vleft[i].insert(0, to_string(root->val) + "->");//note c++ string insert string must use index instead of iterator
        } 
        
        for (int i = 0; i < vright.size(); i ++) {
            vright[i].insert(0, to_string(root->val) + "->");
        }
        
        for (int i = 0; i < vright.size(); i ++) {
            vleft.push_back(vright[i]);
        }
        
        return vleft;
    }
    
    //another method, preorder traversal
    //looks like the function is better than my bottom up solution, it is pre-order
    void helper(struct TreeNode * root, string out, vector<string> & res) {//out can not be pass by reference, why?
        
        if (!root->left && !root->right) {//leaf node
            out += to_string(root->val);
            res.push_back(out);
            return;
        }
        out += to_string(root->val)+ "->";
        
        if (root->left)
            helper(root->left, out, res);
        if (root->right)
            helper(root->right, out, res);
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if (!root)
            return v;
        string s;
        helper(root, s, v);
        return v;
    }
};
