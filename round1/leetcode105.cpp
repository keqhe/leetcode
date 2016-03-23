
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
    unordered_map<int,int> m;
    int searchIndex(vector<int> & inorder, int l, int r, int key) {
        for (int i = l; i <= r; i ++ ) {
            if (inorder[i] == key)
                return i;
        }
        return -1;
    }
    void mapIndex(vector<int> & inorder) {
        for (int i = 0; i < inorder.size(); i ++) {
            m[inorder[i]] = i;
        }
    }
    //preorder: 3, 2, 1, 4, 5
    //inorder:: 1, 2, 3, 4, 5
    //for this problem, we need to assume there is no duplicates, otherwise, we have problem!!!, see the aritcle below
    //this kind of problem, get an BST example is a good start
    //this article is a good read: http://articles.leetcode.com/2011/04/construct-binary-tree-from-inorder-and-preorder-postorder-traversal.html
    //the code here is easier to understand, http://blog.csdn.net/linhuanmars/article/details/24389549
    struct TreeNode * buildPreorderInorder(vector<int>& preorder, vector<int> & inorder, int l1, int r1, int l2, int r2) {
        if (l1 > r1 || l2 > r2)
            return NULL;
        int key = preorder[l1];
        int keyindex = searchIndex(inorder, l2, r2, key);
        
        int lsize = keyindex - l2;
        int rsize = r2 - keyindex;
        
        struct TreeNode * root = new TreeNode (key);
        root->left = buildPreorderInorder(preorder, inorder, l1+1, l1+lsize, l2, keyindex-1);
        root->right = buildPreorderInorder(preorder, inorder, l1+lsize+1, r1, keyindex+1, r2);
        
        return root;
    }
    
    struct TreeNode * buildPreorderInorderMap(vector<int>& preorder, vector<int> & inorder, int l1, int r1, int l2, int r2) {
        if (l1 > r1 || l2 > r2)
            return NULL;
        int key = preorder[l1];
        int keyindex = m[key];//O(1)
        
        int lsize = keyindex - l2;
        int rsize = r2 - keyindex;
        
        struct TreeNode * root = new TreeNode (key);
        root->left = buildPreorderInorder(preorder, inorder, l1+1, l1+lsize, l2, keyindex-1);
        root->right = buildPreorderInorder(preorder, inorder, l1+lsize+1, r1, keyindex+1, r2);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //using index search
        //return buildPreorderInorder(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        //using map to get O(1) search
        mapIndex(inorder);
        return buildPreorderInorderMap(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
