
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
        int carry = 0;
        struct ListNode * h1 = l1;
        struct ListNode * h2 = l2;
        while (l1 && l2) {
            int sum = (l1->val + l2->val + carry);
            l1->val = sum % 10;
            l2->val = sum % 10;
            carry = sum / 10;
            
            if (!l1->next && !l2->next) {//if both l1 and l2 becomes NULL
                if (carry)
                    l1->next = new ListNode(carry);
                return h1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int sum = (l1->val + carry);
            l1->val = sum % 10;
            carry = sum / 10;
            
            if (!l1->next) {
                if (carry)
                    l1->next = new ListNode(carry);
                return h1;
            }
            l1 = l1->next;
        }
        
        while (l2) {
            int sum = (l2->val + carry);
            l2->val = sum % 10;
            carry = sum / 10;
            
            if (!l2->next) {
                if (carry)
                    l2->next = new ListNode(carry);
                return h2;
            }
            l2 = l2->next;
        }
        
    }
};
