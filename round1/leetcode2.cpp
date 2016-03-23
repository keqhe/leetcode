
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
        int len1 = 0;
        int len2 = 0;
        struct ListNode *p1 = l1;
        struct ListNode *p2 = l2;
        struct ListNode * head = NULL;
        while(p1) {
            len1 ++;
            p1 = p1->next;
        }
        while(p2) {
            len2 ++;
            p2 = p2->next;
        }
        //cout << len1 << ' ' << len2 << endl;
        if (len1 >= len2) {
            head = l1;
            p1 = head;
            p2 = l2;
        }
        else {
            head = l2;
            p1 = head;
            p2 = l1;
        }
        //p1 is the longer list
        int carry = 0;
        struct ListNode * prev = NULL;
        while (p1) {
            int tmp = p1->val + carry;
            if (p2) {
                tmp += p2->val;
                p2 = p2->next;
            }
            p1->val = tmp % 10;
            carry = tmp / 10;
            prev = p1;
            p1 = p1->next;
        }
        if (carry) {
            struct ListNode * last = new ListNode(carry);
            prev->next = last;
        }
        
        return head;
    }
};
