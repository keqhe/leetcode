
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
    //reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-partition-list.html
    //basic idea: if (p->val < X) keep it in the oringinal list
    //otherwise, put it into a new list
    //connect the two lists
    ListNode* partition(ListNode* head, int x) {
        struct ListNode* h1 = new ListNode(0);
        struct ListNode* h2 = new ListNode(0);
        h1->next = head;
        
        struct ListNode * prev = h1;
        struct ListNode * p = h2;
        while (head) {
            if (head->val < x) {
                prev = head;
                head = head->next;
            }
            else {
                p->next = head;
                p = p->next;
                head = head->next;
                prev->next = head;
                p->next = NULL;
            }
        }
        
        prev->next = h2->next;
        head = h1->next;
        delete h1;
        delete h2;
        return head;
    }
};
