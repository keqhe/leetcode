
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    //learn good coding ideas from others is as important as finishing the problem by myself
    //because, other people's solution can be much better than mine
    //https://leetcode.com/discuss/63872/c-3-solutions-level-bfs-dfs-recursive
    
    void connect(TreeLinkNode *root) {
        //connect_bfs(root);
        //connect_recur(root);
        connect_preorder(root);
    }
    void connect_preorder(TreeLinkNode * root) {
        if (!root || (root->left == NULL && root->right == NULL))
            return;
        stack<struct TreeLinkNode*> st;
        while (root || !st.empty()) {
            if (root) {
                if (root->left && root->right)
                    root->left->next = root->right;
                    
                if (root->next && root->right)
                    root->right->next = root->next->left;
                
                if (root->right)
                    st.push(root->right);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
            }
        }
    }
    void connect_recur(TreeLinkNode *root) {
        if (!root || (root->left == NULL && root->right == NULL))
            return;
        //if root->left == NULL, then root->right == NULL
        if (root->left != NULL && root->right != NULL)
            root->left->next = root->right;
        if (root->left != NULL && root->right != NULL && root->next != NULL)
            root->right->next = root->next->left; //
        if (root->left != NULL)
            connect_recur(root->left);
        if (root->right != NULL)
            connect_recur(root->right);
        
    }
    void connect_bfs(TreeLinkNode *root) {
        if (!root)
            return;
        queue<vector<struct TreeLinkNode*>> q;//
        vector<struct TreeLinkNode*> v;
        v.push_back(root);
        q.push(v);
        
        while(!q.empty()) {
            vector<struct TreeLinkNode*> line = q.front();
            q.pop();
            
            vector<struct TreeLinkNode*> nextline;
            for (int i = 0; i < line.size(); i ++) {
                if ( i != line.size() - 1) {
                    line[i]->next = line[i + 1];
                }
                if (line[i]->left)
                    nextline.push_back(line[i]->left);
                if (line[i]->right)
                    nextline.push_back(line[i]->right);
            }
            
            if (nextline.size() > 0)
                q.push(nextline);
        }
    }
};
