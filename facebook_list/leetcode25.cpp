
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
    ListNode* reverseList(ListNode* head, ListNode* stop) {
        if (!head || !head->next)
            return head;
        ListNode* prev = nullptr;
        ListNode* p = head;
        while (p != stop) {
            ListNode* next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 1)
            return head;
        ListNode * curr = head;
        for (int i = 0; i < k; i ++) {
            if (curr == nullptr)
                return head;
            curr = curr->next;
        }
        auto newhead = reverseList(head, curr);
        head->next = reverseKGroup(curr, k);
        return newhead;
    }
};
