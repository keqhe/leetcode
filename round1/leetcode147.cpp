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
    //dummy node to simplify the list head operation: 
    //http://bangbingsyb.blogspot.com/2014/11/leetcode-insertion-sort-list.html
    ListNode* insertionSortList(ListNode* head) {
        struct ListNode * newhead = new ListNode(numeric_limits<int>::min());
        
        while (head) {
            struct ListNode * curr = head;
            head = head->next;
            struct ListNode *p = newhead;
            while (p->next && p->next->val <= curr->val)
                p = p->next;
            //p->val <= curr->val while p->next->val > curr->val
            curr->next = p->next;
            p->next = curr;
        }
        head = newhead->next;
        delete newhead;
        return head;
    }
};
