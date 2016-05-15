
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
    struct ListNode * reverseRange(struct ListNode * start, struct ListNode * end) {
        if (!start)
            return NULL;
        if (start == end)
            return start;
        struct ListNode * prev = NULL;
        while (start != end) {
            struct ListNode * next = start->next;
            start->next = prev;
            prev = start;
            start = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next || m == n)
            return head;
        struct ListNode * dummy = new ListNode(0);
        dummy->next = head;
        struct ListNode *before_start = dummy;
        
        int cnt = 0;
        while (cnt < m-1) {//0->1->2->3->4->5->NULL, m = 2, and n = 4
            before_start = before_start->next;
            cnt ++;
        }
        struct ListNode * start = before_start->next;
        struct ListNode *end = start;
        while (cnt < n) {//here "cnt < n" or "cnt <= n"?
            cnt ++;
            end = end->next;
        }
        before_start->next = reverseRange(start, end);
        start->next = end;
        return dummy->next;//strictly speaking, should release dummy memory
    }
};
