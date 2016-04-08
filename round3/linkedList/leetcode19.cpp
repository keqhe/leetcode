
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return NULL;
        struct ListNode * dummy = new ListNode(0);
        dummy->next = head;
        struct ListNode * fast = dummy;
        struct ListNode * slow = dummy;
        int cnt = 0;
        while (cnt < n) {
            fast = fast->next;
            cnt ++;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
