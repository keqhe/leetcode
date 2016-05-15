
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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)
            return head;
        struct ListNode * small = NULL;
        struct ListNode * le = NULL; //large or equal;
        struct ListNode *p1 = small, *p2 = le;
        while (head) {
            if (head->val < x) {
                if (!small) {
                    small = head;
                    p1 = small;
                }
                else {
                    p1->next = head;
                    p1 = head;
                }
            }
            else {
                if (!le) {
                    le = head;
                    p2 = le;
                }
                else {
                    p2->next = head;
                    p2 = head;
                }
            }
            head = head->next;
        }
        if (p2) //initially forgot this, think about test case [1,1], 2
            p2->next = NULL;//end the second list
        if (small)
            p1->next = le;
        else
            small = le;
        return small;
    }
};
