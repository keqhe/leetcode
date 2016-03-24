
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return NULL;
        struct ListNode * p = head;
        while (head && head->next) {
            if (head->val == head->next->val) {
                struct ListNode * tmp = head->next;
                head->next = head->next->next;
                delete tmp;
            }
            else {
                head = head->next;
            }
        }
        
        return p;
    }
};
