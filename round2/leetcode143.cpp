
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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)//0, 1, 2
            return;
        struct ListNode * slow = head;
        struct ListNode * fast = head;
        struct ListNode * prev = NULL;
        struct ListNode * second;
        struct ListNode * dummy = new ListNode(0);
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //[1,2,3]
        //or [1,2,3,4]
        if (fast) {//odd
            second = slow->next;
            slow->next = NULL;
        }
        else {
            second = slow;
            prev->next = NULL;
        }
        
        second = reverseList(second);
        struct ListNode * l1 = head;
        struct ListNode * l2 = second;
        struct ListNode * p = dummy;
        int cnt = 1;
        while (l1 && l2) {
            if (cnt % 2 == 1) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
            cnt ++;
        }
        if (l1)
            p->next = l1;
        if (l2)
            p->next = l2;
        head = dummy->next;
        delete dummy;
    }
};
