
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
    //two pointers, ref: https://leetcode.com/discuss/87494/from-wrong-to-ac-c-implementation
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode * dummy = new ListNode(0);
        dummy->next = head;
        struct ListNode * ahead = dummy;
        struct ListNode * behind = dummy;
        for (int i = 0; i <=n; i ++)
            ahead = ahead->next;
        //now ahead - behind = n
        while (ahead) {
            behind = behind->next;
            ahead = ahead->next;
        }
        struct ListNode * tmp = behind->next;
        behind->next = behind->next->next;
        delete tmp;
        struct ListNode * res = dummy->next;
        delete dummy;
        return res;
    }
};
