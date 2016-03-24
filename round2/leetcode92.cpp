
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
    struct ListNode * reverseList(struct ListNode * head) {
        if (!head || !head->next)
            return head;
        struct ListNode * prev = NULL;
        while (head) {
            struct ListNode * p = head;
            head = head->next;
            p->next = prev;
            prev = p;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        struct ListNode * dummy = new ListNode(0);
        dummy->next = head;
        struct ListNode * p = dummy;
        
        struct ListNode * p1 = NULL;
        struct ListNode * p2 = NULL;
        int cnt = 1;
        while (p) {
            if (cnt == m)
                p1 = p;
            if (cnt == n+1)
                p2 = p;
            p = p->next;
            cnt ++;
        }
        cout << p1->val << " " << p2->val << endl;
        struct ListNode * third = p2->next;
        p2->next = NULL;
        struct ListNode * second = p1->next;
        struct ListNode * new_second = reverseList(second);
        p1->next = new_second;
        
        if (second)
         second->next = third;
        /*//this works
        while (second->next) {
            second = second->next;
        }*/
        return dummy->next;
    }
};
