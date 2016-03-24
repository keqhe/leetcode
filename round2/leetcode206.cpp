
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
    ListNode* reverseList_iterative(ListNode* head) {
        if (!head)
            return NULL;
        struct ListNode * prev = NULL;
        while (head) {
            struct ListNode * p = head;
            head = head->next;
            p->next = prev;
            prev = p;
        }
        
        return prev;
    }
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        struct ListNode * newhead = reverseList(head->next);
        head->next = NULL;
        struct ListNode * p = newhead;
        while (p->next) {
            p = p->next;
        }
        p->next = head;
        
        return newhead;
    }
    
     ListNode* reverseList__(ListNode* head) {
        if (!head || !head->next)
            return head;
        struct ListNode * fast = head;
        struct ListNode * slow = head;
        struct ListNode * prev = NULL;
        struct ListNode * mid = NULL;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (!fast) {
            mid = slow;
            prev->next = NULL;
        }
        else {
            prev->next = NULL;
            mid = slow;
        }
        
        struct ListNode * p1 = reverseList(mid);
        struct ListNode * p2 = reverseList(head);
        
        struct ListNode * p = p1;
        while (p && p->next) {
            p = p->next;
        }
        if (p)
            p->next = p1;
        else
            p1 = p2;
        return p1;
    }
    
};
