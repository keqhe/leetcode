
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return NULL;
        struct ListNode * dummy = new ListNode(0);
        dummy->next = head;
        struct ListNode * curr = dummy;
        while (curr && curr->next) {
            if (curr->next->val == val) {
                struct ListNode * del = curr->next;
                curr->next = curr->next->next;
                delete del;
            }
            else {
                curr = curr->next;
            }
        }
        return dummy->next;//strictly speaking, need to release the memory of dummy
    }
};
