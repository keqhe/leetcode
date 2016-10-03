
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return head;
        ListNode * l1 = nullptr;
        ListNode * l2 = nullptr;
        
        l1 = head;
        auto prev1 = l1;
        l2 = head->next;
        auto prev2 = l2;
        
        auto p = head->next;
        int count = 0;
        while (p) {
            p = p->next;
            count ++;
            if (count % 2 == 0) {
                prev2->next = p;
                prev2 = p;
            }
            else {
                prev1->next = p;
                prev1 = p;
            }
        }
        if (prev2)
            prev2->next = nullptr;
        p = l1;
        while (p && p->next) {
            p = p->next;
        }
        p->next = l2;
        return l1;
    }
};
