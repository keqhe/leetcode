#include<iostream>
#include<string>
#include<limits>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool validBST(struct TreeNode * root, long Min, long Max) {
        if (!root)
            return true;
        if (root->val < Max && root->val > Min) {
            return validBST(root->left, Min, root->val) && validBST(root->right, root->val, Max);
        }
        return false;
        
    }
    int countNodes(struct TreeNode * root) {
        if (!root)
            return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    //this version is O(nlogn)
    int largestBSTSubtree_naive(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        if (validBST(root, numeric_limits<long>::min(), numeric_limits<long>::max()))
            return countNodes(root);
        else
            return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
    //there is an O(n) solution, ref: http://articles.leetcode.com/largest-binary-search-tree-bst-in
    //idea: bottom up solution
    int countBSTNodes(struct TreeNode* root, int & Min, int & Max, int & maxCount) {
        if (!root)
            return 0;
        int isBST = true;
        int currMin;
        int currMax;
        
        int leftCount = countBSTNodes(root->left, Min, Max, maxCount);
        currMin = (leftCount == 0 ? root->val : Min);//initialize  Min
        
        if (leftCount == -1 || (leftCount != 0 && root->val <= Max))//if root->val is smaller than or equal to left subtree's Max, then isBST is false;
            isBST = false;
            
        int rightCount = countBSTNodes(root->right, Min, Max, maxCount);
        currMax = (rightCount == 0 ? root->val : Max);////initialize  Max
        
        if (rightCount == -1 || (rightCount != 0 && root->val >= Min)) //if root->val is larger than or equal to right subtree's Min, then isBST is false;
            isBST = false;
        if (isBST) {
            Min = currMin;////initialize  Min
            Max = currMax;
            
            maxCount = max(maxCount, leftCount+rightCount+1);
            return leftCount+rightCount+1;
        }
        else 
            return -1;
    }
    int largestBSTSubtree(TreeNode* root) {
        int maxCount = 0;
        int Min, Max;
        countBSTNodes(root, Min, Max, maxCount);
        return maxCount;
    }
};

int main() {
	class Solution sn;
	return 0;
}
