
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Result {
  bool isBST;
  int size;
  long min_val;
  long max_val;
  Result(bool a, int b, long c, long d) {
      isBST = a;
      size = b;
      min_val = c;
      max_val = d;
  }
};
class Solution {
public:
    Result helper(TreeNode* root, int& max_size) {
        
        if (!root) {
            return Result(true, 0, numeric_limits<long>::max(), numeric_limits<long>::min());
        }
        //cout << root->val << endl;
        Result l = helper(root->left, max_size);
        Result r = helper(root->right, max_size);
        //cout << l.isBST << " " << r.isBST << endl;
        //cout << l.max_val << " " << r.min_val << endl;
        if (l.isBST && r.isBST) {
            if (l.max_val < root->val && root->val < r.min_val) {
                cout << "haha debug: " << l.size + r.size + 1 << endl;
                max_size = max(max_size, l.size + r.size + 1);
                long left_bound = l.min_val;
                if (l.min_val == numeric_limits<long>::max())
                    left_bound = root->val;
                long right_bound = r.max_val;
                if (r.max_val == numeric_limits<long>::min())
                    right_bound = root->val;
                return Result(true, l.size + r.size + 1, left_bound, right_bound);
            }
        }
        
        return Result(false, 0, 0, 0);
    }
    int largestBSTSubtree(TreeNode* root) {
        if (!root)
            return 0;
        int max_size = 0;
        Result res = helper(root, max_size);
        //cout << "debug.." << endl;
        return max_size;
    }
};
