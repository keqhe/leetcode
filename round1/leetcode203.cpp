
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
    //1->1->1->2->2, 1
    //1->1->1, 1
    //NULL
    //1->1->1->2->1->1, 1
    ListNode* removeElements(ListNode* head, int val) {
        struct ListNode * start = head;
        struct ListNode * prev = NULL;
        if (!head) 
            return head;
        while (head) {
            if (head->val == val) {
                struct ListNode * n = head;
                head = head->next;
                delete n;
            }
            else
                break;
        }
        start = head;//first entry but not = val
        while(start) {
            if (start->val == val) {
                struct ListNode * n = start;
                prev->next = start->next;
                start = start->next;
                delete n;
            }
            else {
                prev = start;
                start = start->next;
            }
        }
        return head;
    }
};
