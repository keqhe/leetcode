
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
    //merge sort is applied here, quicksort is poor (because locating index is slow), head sort not applicable 
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        struct ListNode * newhead = NULL;
        struct ListNode * prev = NULL;
        
        if (l1->val <= l2->val)
            newhead = l1;
        else newhead = l2;
        
        while(l1 && l2) {
            if (l1->val <= l2->val) {
                if(prev)
                    prev->next = l1;
                prev = l1;
                l1 = l1->next;
            }
            else {
                if (prev)
                    prev->next = l2;
                prev = l2;
                l2 = l2->next;
            }
        }
        
        if(!l1)
            prev->next = l2;
        if (!l2)
            prev->next = l1;
        return newhead;
    }
    void split(struct ListNode * head, struct ListNode ** h1, struct ListNode **h2) {
        if (head == NULL) {
            *h1 = NULL;
            *h2 = NULL;
        }
        if (head->next == NULL) {
            *h1 = head;
            *h2 = NULL;
            return;
        }
        struct ListNode *p1 = head;
        struct ListNode *p2 = head;
        struct ListNode * prev = NULL;
        //[1,2]
        //[1, 2, 3]
        //[1,2,3,4]
        while (p2 && p2->next) {
            prev = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        if (p2) {//odd
            *h2 = p1->next;
            p1->next = NULL;
            *h1 = head;
        }
        else {//even
            prev->next = NULL;
            *h1 = head;
            *h2 = p1;
        }
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        struct ListNode *p1 = NULL;
        struct ListNode *p2 = NULL;
        struct ListNode * head1 = NULL;
        struct ListNode * head2 = NULL;
        split(head, &p1, &p2);
        head1 = sortList(p1);
        head2 = sortList(p2);
        return mergeTwoLists(head1, head2);
    }
};
