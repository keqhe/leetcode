
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
    ListNode* swapPairs(ListNode* head) {
        struct ListNode * start = head;
        struct ListNode * prev = NULL;
        
        while (start != NULL && start->next != NULL) {
            struct ListNode * curr = start;
            start = start->next->next;
            
            struct ListNode * nxt = curr->next;
            curr->next = nxt->next;
            nxt->next = curr;
            if (prev != NULL)
                prev->next = nxt;
            prev = curr;
            
            if (curr == head) {
                head = nxt;
            }
        }
        
        return head;
    }
};
