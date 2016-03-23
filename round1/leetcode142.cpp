
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
    //reference: http://www.cnblogs.com/hiddenfox/p/3408931.html
    //idea1: fast在后面每次循环都向slow靠近1，所以一定会相遇
    //X----Y---Z----Y, X->Y has a steps, Y->Z has b steps, Z->Y has c steps, when fast and slow first meet, we have
    //2(a+b) = a+b+c+b, so we have a == c, that is X->Y has Z->Y has the same distance. 
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        struct ListNode * fast = head;
        struct ListNode * slow = head;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;//meet at Z
        }
        if (fast == NULL || fast->next == NULL)
            return NULL;//no loop case
        else {
            while (head != slow) {
                head = head->next;
                slow = slow->next;
            }
            return slow;
        }
    }
};
