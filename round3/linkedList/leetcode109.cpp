
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
            struct TreeNode * root = new TreeNode(head->val);
            return root;
        }
        
        struct ListNode * slow = head;
        struct ListNode * fast = head;
        struct ListNode * prev = NULL;
        struct ListNode * mid = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        struct ListNode * l1, *l2;
        if (fast) {//1->2->3->NULL
            mid = slow;
            l1 = head;
            prev->next = NULL;
            l2 = slow->next;
        }
        else {//1->2->3->4->NULL
            l1 = head;
            prev->next = NULL;
            l2 = slow->next;
            mid = slow;
        }
        struct TreeNode * root = new TreeNode(mid->val);
        root->left = sortedListToBST(l1);
        root->right = sortedListToBST(l2);
        return root;
    }
};
