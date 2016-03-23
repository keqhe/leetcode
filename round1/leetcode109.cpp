
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
    struct ListNode * helper(ListNode * head, struct ListNode ** left, struct ListNode **right) {
        if (head == NULL || head->next == NULL)
            return head;
        struct ListNode * fast = head;
        struct ListNode * slow = head;
        struct ListNode * prev = NULL;
        
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        if (prev)
            prev->next = NULL;
        *left = head;
        *right = slow->next;
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        struct ListNode * mid = NULL;
        struct TreeNode * root = NULL;
        struct ListNode *l = NULL;
        struct ListNode *r = NULL;
        
        mid = helper(head, &l, &r);
        
        if (mid) {
            root = new TreeNode(mid->val);
            root->left = sortedListToBST(l);
            root->right = sortedListToBST(r);
        }
        return root;
    }
};
