
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
        if (!head) 
            return NULL;
        struct ListNode * dummy = new ListNode(0);
        dummy->next = head;
        struct ListNode * p = head;
        struct ListNode * prev = dummy;
        long prev_val = numeric_limits<long>::min();
        while (p) {
            if ((prev_val == p->val) || (p->next && p->next->val == p->val)) {
                struct ListNode * tmp = p;
                prev_val = p->val;
                prev->next = p->next;
                p = p->next;
                delete tmp;
            }
            else {
                prev = p;
                p = p->next;
            }
        }
        return dummy->next;
    }
};
