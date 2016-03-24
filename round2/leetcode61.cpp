
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        int count = 0;
        struct ListNode * p = head;
        while (p) {
            count ++;
            p = p->next;
        }
        k = k % count;
        if (k == 0)
            return head;
            
        int pos = count - k;
        p = head;
        count = 0;
        struct ListNode * l1 = head;
        struct ListNode * l2 = NULL;
        while (p) {
            count ++;
            if (count == pos) {
                l2 = p->next;
                p->next = NULL;
                break;
            }
            p = p->next;
        }
        p = l2;
        while (p->next) {
            p = p->next;
        }
        p->next = l1;
        return l2;
    }
};
