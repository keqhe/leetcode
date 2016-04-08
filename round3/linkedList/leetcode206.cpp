
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        struct ListNode * prev = NULL;
        while (head) {
            struct ListNode * curr = head;
            head = head->next;
            curr->next = prev;
            prev = curr;
            //head = head->next; put here is WRONG
        }
        return prev;
    }
};
