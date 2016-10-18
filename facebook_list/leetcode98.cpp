
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
  bool is_bst;
  long Min;
  long Max;
  Result(bool a, long b, long c) {
      is_bst = a;
      Min = b;
      Max = c;
  }
};

class Solution {
public:
    Result helper(TreeNode* root) {
        if (!root)
            return Result(true, numeric_limits<long>::max(), numeric_limits<long>::min());
        Result left = helper(root->left);
        Result right = helper(root->right);
        if (!left.is_bst || !right.is_bst) {
            return Result(false, 0, 0);
        }
        else {
            if (left.Max < root->val && root->val < right.Min) {
                return Result(true, min(left.Min, (long)root->val), max((long)root->val, right.Max));
            }
            else {
                return Result(false, 0, 0);
            }
        }
    }
    bool isValidBST(TreeNode* root) {
        Result r = helper(root);
        return r.is_bst;
    }
};
