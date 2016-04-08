
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        int len = 0;
        struct ListNode * curr = head;
        while (curr) {
            len ++;
            curr = curr->next;
        }
        k = k % len;
        if (k == 0)
            return head;
        struct ListNode * fast = head;
        struct ListNode * slow = head;
        int cnt = 0;
        while (cnt < k) {
            cnt ++;
            fast = fast->next;
        }
        while (fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        struct ListNode * nh = slow->next;
        fast->next = head;
        slow->next = NULL;
        return nh;
    }
};
