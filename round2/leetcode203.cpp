
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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            struct ListNode * d = head;
            head = head->next;
            delete d;
        } 
        //now head points to the first node whose value is not val
        struct ListNode * p = head;
        //while (p->next) {//if p is NULL, this is run time error
        while(p && p->next) { 
            if (p->next->val == val) {
                struct ListNode * d = p->next;
                p->next = p->next->next;
                delete d;
            }
            else
                p = p->next;
            
        }
        return head;
    }
};
