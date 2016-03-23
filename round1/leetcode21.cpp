
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        struct ListNode * newhead = NULL;
        struct ListNode * prev = NULL;
        
        if (l1->val <= l2->val)
            newhead = l1;
        else newhead = l2;
        
        while(l1 && l2) {
            if (l1->val <= l2->val) {
                if(prev)
                    prev->next = l1;
                prev = l1;
                l1 = l1->next;
            }
            else {
                if (prev)
                    prev->next = l2;
                prev = l2;
                l2 = l2->next;
            }
        }
        
        if(!l1)
            prev->next = l2;
        if (!l2)
            prev->next = l1;
        return newhead;
    }
};
