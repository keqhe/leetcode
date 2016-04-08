
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        struct ListNode * prev = NULL;
        struct ListNode * nh = NULL;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                if (!nh) {
                    nh = l1;
                    prev = nh;
                    l1 = l1->next;
                }
                else {
                    prev->next = l1;
                    prev = l1;
                    l1 = l1->next;
                }
            }
            else {
                if (!nh) {
                    nh = l2;
                    prev = nh;
                    l2 = l2->next;
                }
                else {
                    prev->next = l2;
                    prev = l2;
                    l2 = l2->next;
                }
            }
        }
        if (l1)
            prev->next = l1;
        else if (l2)
            prev->next = l2;
        else
            prev->next = NULL;
        return nh;
    }
};
