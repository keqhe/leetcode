
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
    //https://discuss.leetcode.com/topic/50897/o-n-time-o-1-space-at-most-2-pass-neat-solution
    ListNode* plusOne(ListNode* head) {
        ListNode * last_not_nine = nullptr;
        auto p = head;
        while (p != nullptr) {
            if (p->val != 9) {
                last_not_nine = p;
            }
            p = p->next;
        }
        if (last_not_nine != nullptr) {
            last_not_nine->val += 1;
            p = last_not_nine->next;
            while (p) {
                p->val = 0;
                p = p->next;
            }
            return head;
        }
        else {
            ListNode * newhead = new ListNode(1);
            newhead->next = head;
            p = head;
            while (p) {
                p->val = 0;
                p = p->next;
            }
            return newhead;
        }
    }
};
