
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
    //the first thought i have is to use stack, but it needs O(1) memory
    int getLen(struct ListNode * p) {
        int len = 0;
        while (p) {
            len ++;
            p = p->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        int len1 = getLen(headA);
        int len2 = getLen(headB);
        int lenDiff = abs(len1-len2);
        struct ListNode * l1;
        struct ListNode * l2;
        if (len1 >= len2) {
            l1 = headA;
            l2 = headB;
        }
        else if (len1 < len2) {
            l1 = headB;
            l2 = headA;
        }
        while (lenDiff) {
            l1 = l1->next;
            lenDiff --;
        }
        while (l1 && l2) {
            if (l1 != l2) {
                l1 = l1->next;
                l2 = l2->next;
            }
            else {
                return l1;
            }
        }
        return NULL;
    }
};
