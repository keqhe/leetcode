
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
    struct ListNode *mergeList(struct ListNode * head1, struct ListNode * head2) {
        if (!head1 && !head2)
            return NULL;
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        struct ListNode * nh = NULL;
        struct ListNode * prev = NULL;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                struct ListNode * t = head1;
                head1 = head1->next;
                if (!nh) {
                    nh = t;
                    prev = t;
                }
                else {
                    prev->next = t;
                    prev = t;
                }
            }
            else {
                struct ListNode * t = head2;
                head2 = head2->next;
                if (!nh) {
                    nh = t;
                    prev = t;
                }
                else {
                    prev->next = t;
                    prev = t;
                }
            }
        }
        if (head1)
            prev->next = head1;
        if (head2)
            prev->next = head2;
        return nh;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        struct ListNode * slow = head;
        struct ListNode * fast = head;
        struct ListNode * prev = NULL;
        struct ListNode * mid = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        struct ListNode * l1, *l2;
        if (fast) {//1->2->3
            l1 = head;
            l2 = prev->next;
            prev->next = NULL;
        }
        else {
            l1 = head;
            l2 = prev->next;
            prev->next = NULL;
        }
        l1 = sortList(l1);
        l2 = sortList(l2);
        return mergeList(l1, l2);
    }
};
