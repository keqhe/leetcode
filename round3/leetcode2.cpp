
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        struct ListNode * head = NULL;
        struct ListNode * prev = head;
        int carry = 0;
        while (l1 && l2) {
            int curr = carry + l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            struct ListNode * tmp = new ListNode(curr % 10);
            if (!head) {
                head = tmp;
                prev = tmp;
            }
            else {
                prev->next = tmp;
                prev = tmp;
            }
            carry = curr/10;
        }
        while (l1) {
            int curr = carry + l1->val;
            l1 = l1->next;
            struct ListNode * tmp = new ListNode(curr % 10);
            if (!head) {
                head = tmp;
                prev = tmp;
            }
            else {
                prev->next = tmp;
                prev = tmp;
            }
            carry = curr/10;
        }
        
        while (l2) {
            int curr = carry + l2->val;
            l2 = l2->next;
            struct ListNode * tmp = new ListNode(curr % 10);
            if (!head) {
                head = tmp;
                prev = tmp;
            }
            else {
                prev->next = tmp;
                prev = tmp;
            }
            carry = curr/10;
        }
        
        if (carry) {
            struct ListNode * tmp = new ListNode(carry);
            if (!head) {
                head = tmp;
                prev = tmp;
            }
            else {
                prev->next = tmp;
                prev = tmp;
            }
        }
        return head;
    }
};
