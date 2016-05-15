
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        struct ListNode * dummy = new ListNode(0);
        //dummy->next = head; // adding this TLE, think why, first part can not be connected with second part!
        struct ListNode * curr = head;
        while (curr) {
            struct ListNode * nxt = curr->next;
            struct ListNode * p = dummy;
            
            while (p && p->next) {
                if (p->next->val < curr->val) {
                    p = p->next;
                }
                else {
                    break;
                }
            }
            curr->next = p->next;
            p->next = curr;
            curr = nxt;
        }
        
        return dummy->next;
    }
};
