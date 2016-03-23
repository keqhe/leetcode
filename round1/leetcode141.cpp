
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
    //two pointers, fast and slow, it is guaranteed that fast and slow will meet
    //this example, 1->2 and 2 connect to head 1
    bool hasCycle(ListNode *head) {
        struct ListNode * fast = head;
        struct ListNode * slow = head;
        
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};
