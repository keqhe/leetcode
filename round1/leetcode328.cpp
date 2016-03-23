
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return NULL;
        if (!head->next || !head->next->next) //1 or 2 nodes
            return head;
        struct ListNode * odd = head;
        struct ListNode * even = head->next;
        struct ListNode * even_head = even;
        
        int i = 0;
        struct ListNode * p = even->next;
        while (p) {
            if (i % 2 == 0) {
                odd->next = p;
                odd = p;
            }
            else {
                even->next = p;
                even = p;
            }
            i ++;
            p = p ->next;
        }
        
        odd->next = even_head;
        even->next = NULL;
        return head;
    }
};
