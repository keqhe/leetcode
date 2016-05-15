
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
            struct ListNode * next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        struct ListNode * fast = head;
        struct ListNode * slow = head;
        struct ListNode * prev = NULL;
        struct ListNode * mid = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        struct ListNode *l1 = NULL, *l2 = NULL;
        if (fast) {//1->2->3->NULL
            l1 = head;
            l2 = slow->next;
            slow->next = NULL;
        }
        else {//1->2->3->4->NULL
            l1 = head;
            l2 = slow;
            prev->next = NULL;
        }
        l2 = reverseList(l2);
        if (l2)
            cout << l2->val << endl;
        struct ListNode *last;
        int cnt = 0;
        while (l1 && l2) {
            cnt ++;
            if (cnt % 2 == 1) {
                if (!last) {
                    last = l1;
                    l1 = l1->next;
                }
                else {
                    last->next = l1;
                    last = l1;
                    l1 = l1->next;
                }
            }
            else {
                last->next = l2;
                last = l2;
                l2 = l2->next;
            }
        }
        if (l1)
            last->next = l1;
        if (l2)
            last->next = l2;
    }
};
