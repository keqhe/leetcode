
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
        if (k == 0 || !head)
            return head;
        int len = 1;
        struct ListNode * p = head;
        while (p->next) {
            len += 1;
            p = p->next;
        }
        //now p points to the last non-NULL element
        p->next = head;
        k = len - k % len; //e.g., 5 - 2 % 5 = 3;
        while (k > 0) {
            p = p->next;
            k --;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};
