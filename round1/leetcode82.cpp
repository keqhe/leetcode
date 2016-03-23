
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
    //do not forgot delete..
    //basic idea: prev_val == curr->val || (curr->next && curr->val == curr->next->val)
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        //[1, 1, 2]
        //[1, 1, 1]
        //[1, 1, 2, 2, 3]
        long prev_val = numeric_limits<long>::max();
        while (head) {
            if ((prev_val == head->val) || (head->next && head->val == head->next->val)) {
                prev_val = head->val;
                struct ListNode * tmp = head;
                head = head->next;
                //cout << "delete.. " << tmp->val << endl;
                delete tmp;
            }
            else 
                break;//DO NOT forget to break, otherwise, infinite loop!!!
        }
        if (!head)
            return NULL;
        cout << head->val << endl;
        prev_val = numeric_limits<long>::max();
        struct ListNode * p = head->next;
        struct ListNode * prev = head;
        while (p) {
            if ((prev_val == p->val) || (p->next && p->val == p->next->val)) {
                prev_val = p->val;
                struct ListNode * tmp = p;
                p = p->next;
                prev->next = p;
                //cout << "delete.. " << tmp->val << endl;
                delete tmp;
            }
            else {
                prev = p;
                prev_val = p->val;
                p = p->next;
            }
        }
        return head;
    }
};
