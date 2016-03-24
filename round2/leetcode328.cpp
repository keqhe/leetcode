
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
        if (!head || !head->next || !head->next->next) {
            return head;
        }
        
        struct ListNode * l1 = head;
        struct ListNode * l2 = head->next;
        struct ListNode * p = head->next->next;
        struct ListNode * l2_head = l2;
        int cnt = 1;
        while (p) {
            struct ListNode * tmp = p;
            p = p->next;
            if (cnt % 2 == 1) {
                l1->next = tmp;
                l1 = l1->next;
            }
            else {
                l2->next = tmp;
                l2 = l2->next;
            }
            cnt ++;
        }
        l2->next = NULL;//important
        l1->next = l2_head;
        return head;
    }
};
