
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        if (!head->next) {
            struct TreeNode * p = new TreeNode(head->val);
            return p;
        }
       struct ListNode * fast = head;
       struct ListNode * slow = head;
       struct ListNode * prev = NULL;
       while (fast && fast->next) {
           prev = slow;
           slow = slow->next;
           fast = fast->next->next;
       }
       //[1,2]
       if (!fast) {
           struct TreeNode * root = new TreeNode(slow->val);
           prev->next = NULL;
           root->left = sortedListToBST(head);
           root->right = sortedListToBST(slow->next);
           
       }//[1,2,3]
       else {
           struct TreeNode * root = new TreeNode(slow->val);
           prev->next = NULL;
           root->left = sortedListToBST(head);
           root->right = sortedListToBST(slow->next);
       }
    }
};
