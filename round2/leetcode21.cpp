
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        struct ListNode * head = NULL;
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        struct ListNode * curr = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
        }
        if (l1)
            curr->next = l1;
        if (l2)
            curr->next = l2;
        return head;
    }
};
