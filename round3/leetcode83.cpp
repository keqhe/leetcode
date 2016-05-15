
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        struct ListNode * curr = head;
        struct ListNode * next = curr->next;
        while (curr) {
            next = curr->next;
            if (next) {
                if (next->val == curr->val) {
                    curr->next = next->next;
                    delete next;
                }
                else {
                    curr = next;
                }
            }
            else
                break;
        }
        return head;
    }
};
