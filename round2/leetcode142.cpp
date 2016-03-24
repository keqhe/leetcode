
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
    //the distance between list head and cycle starting point is L,
    /*the distance between meeting point and starting point is X
    cycle length is C
    2*(L+X) = L + C + X; 2L+2X = L + X + n*C;
    so, L = C - X;
    */
    ListNode *detectCycle(ListNode *head) {
        struct ListNode * fast = head;
        struct ListNode * slow = head;
        bool cycle = false;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                cycle = true;
                break;
            }
        }
        if (cycle == false)
            return NULL;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
