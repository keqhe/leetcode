
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
    //ref: https://leetcode.com/discuss/55682/o-logn-java-solution-with-two-stacks-following-hint
    //in order traversal: http://segmentfault.com/a/1190000003797291
    //time complexity is O(N)
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        if (k <= 0)
            return res;
            
        queue<int> q;
        stack<struct TreeNode*> st;//for inorder traversal
        
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
        
        while (!st.empty()) {
            struct TreeNode * tmp = st.top();
            st.pop();
            if (q.size() < k) {
                q.push(tmp->val);
            }
            else {
                double diff1 = abs((double)tmp->val - (double)target);
                double diff2 = abs((double)q.front() - (double)target);
                
                if (diff1 < diff2) {
                    q.pop();
                    q.push(tmp->val);
                }
            }
            tmp = tmp->right;
            while (tmp) {
                st.push(tmp);
                tmp = tmp->left;
            }
        }
        
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
