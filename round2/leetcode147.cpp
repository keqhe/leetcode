
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
    //[1,3,2]
    ListNode* insertionSortList(ListNode* head) {
        struct ListNode * tmp = new ListNode(numeric_limits<int>::min());
        tmp->next = head;
        struct ListNode * prev = tmp;
        struct ListNode * curr = head;
        while (curr) {
            if (curr->val >= prev->val) {
                prev = curr;
                curr = curr->next;
            }
            else {
                prev->next = curr->next;
                
                struct ListNode * p = tmp;
                while (p && p->next) {
                    if (p->next->val < curr->val)
                        p = p->next;
                    else
                        break;
                }
                curr->next = p->next;
                p->next = curr;
                //process next node
                curr = prev->next;
            }
        }
        
        return tmp->next;
    }
};
