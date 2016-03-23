
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
    //ref: https://leetcode.com/discuss/61426/c-elegant-and-small
    struct ListNode * reverseList(struct ListNode * start, struct ListNode * end) {
        struct ListNode * prev = end;
        while (start != end) {
            struct ListNode * tmp = start->next;
            start->next = prev;
            prev = start;
            start = tmp;
        }
        
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1)
            return head;
        struct ListNode * curr = head;
        for (int i = 0; i < k; i ++) {
            if (!curr)
                return head;
            curr = curr->next;
        }
        struct ListNode * nh = reverseList(head, curr);
        head->next = reverseKGroup(curr, k);
        
        return nh;
    }
};
