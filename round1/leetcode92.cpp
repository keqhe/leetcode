
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
    struct ListNode * reverse(struct ListNode * start) {
        struct ListNode * prev = NULL;
        struct ListNode * p = start;
        while (p) {
            struct ListNode * next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next)
            return head;
        struct ListNode * newhead = new ListNode(0);
        newhead->next = head;
        
        int len = 0;
        struct ListNode * h2 = head;
        struct ListNode * h3 = NULL;
        struct ListNode * p1, *p2;
        p1 = newhead;
        
        struct ListNode * p = head;
        while (p) {
            len ++;
            if (len == m-1) {
                h2 = p->next;
                p1 = p; //p1 records where to close list, i.e., p1->next = NULL;
            }
            if (len == n) {
                h3 = p->next;
                p2 = p;
            }
            p = p->next;
        }
        
        p1->next = NULL;
        p2->next = NULL;
        h2 = reverse(h2);
        
        p = newhead;
        while (p->next) {
            p = p->next;
        }
        p->next = h2;
        p = h2;
        while(p->next) {
            p = p->next;
        }
        p->next = h3;
        
        return newhead->next;
    }
};
