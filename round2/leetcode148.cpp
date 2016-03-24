
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
    //merge two sorted list, similar as merge sort's merge function
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        struct ListNode * head = NULL;
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        struct ListNode * curr = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
        }
        if (l1)
            curr->next = l1;
        if (l2)
            curr->next = l2;
        return head;
    }
    //merge sort, ref: https://leetcode.com/discuss/73367/c-merge-sort-solution
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        struct ListNode * slow = head;
        struct ListNode * fast = head;
        struct ListNode * prev = NULL;
        //example, [1, 2]
        //[1,2,3]
        //[1,2,3,4]
        //while (slow && fast->next) { this is wrong
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev)
            prev->next = NULL;//terminate the first list;
        //slow points to the starting of the second list;
        struct ListNode * l1 = sortList(head);
        struct ListNode * l2 = sortList(slow);
        struct ListNode * nh = mergeTwoLists(l1, l2);
        return nh;
    }
};
