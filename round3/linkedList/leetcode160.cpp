
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        int lenA = 0;
        int lenB = 0;
        struct ListNode* p = headA;
        while (p) {
            lenA ++;
            p = p->next;
        }
        p = headB;
        while (p) {
            lenB ++;
            p = p->next;
        }
        struct ListNode * pA = headA;
        struct ListNode * pB = headB;
        while (lenA > lenB) {
            pA = pA->next;
            lenA --;
        }
        while (lenB > lenA) {
            pB = pB->next;
            lenB --;
        }
        while (pA && pB) {
            if (pA == pB)
                return pA;
            else {
                pA = pA->next;
                pB = pB->next;
            }
        }
        return NULL;
    }
};
