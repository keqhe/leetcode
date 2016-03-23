
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
        struct ListNode * start = head;
        while(start) {
            struct ListNode * next = start->next;
            while(next) {
                if (next->val == start->val) {
                    struct ListNode * todelete = next;
                    next = next->next;
                    delete todelete;
                }
                else
                    break;
            }
            start->next = next;
            start = start->next;
        }
        return head;
    }
};
