
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 1)
            return head;
        deque<struct ListNode*> de;
        struct ListNode * curr = head;
        struct ListNode * dummy = new ListNode(0);
        struct ListNode * p = dummy;
        while (curr) {
            if (de.size() < k) {
                de.push_back(curr);
            }
            else {
                //have k points in deque now
                while (!de.empty()) {
                    p->next = de.back();
                    de.pop_back();
                    p = p->next;
                }
                de.push_back(curr);
            }
            curr = curr->next;
        }
        //leftover
        if (de.size() < k) {
            while (!de.empty()) {
                p->next = de.front();
                de.pop_front();
                p = p->next;
            }
        }
        else {
            //have k points in deque now
            while (!de.empty()) {
                p->next = de.back();
                de.pop_back();
                p = p->next;
            }
        }
        
        p->next = NULL;
        
        struct ListNode * res = dummy->next;
        delete dummy;
        return res;
    }
};
