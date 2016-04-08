
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
        struct ListNode * dummy = new ListNode(0);
        dummy->next = head;
        struct ListNode * curr = head;
        struct ListNode * prev = dummy;
        long last = numeric_limits<int>::max();
        while (curr) {
            struct ListNode * next = curr->next;
            if (curr->val == last || (next && next->val == curr->val)) {
                last = curr->val;
                prev->next = next;
                delete curr;
            }
            else {
                prev = curr;
                last = curr->val;
            }
            curr = next;
        }
        return dummy->next;
    }
};
