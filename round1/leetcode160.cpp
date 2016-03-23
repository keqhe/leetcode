
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
        struct ListNode * a = headA;
        struct ListNode * b = headB;
        struct ListNode * ret = 0;
        int lenA = 0;
        int lenB = 0;
        while(a) {
            lenA ++;
            a = a->next;
        }
        while(b) {
            lenB ++;
            b = b->next;
        }
        a = headA;
        b = headB;
        if (lenA > lenB) {
            while(lenA > lenB) {
               lenA --; 
               a = a->next;
            }
        }
        else if (lenB > lenA) {
            while(lenB > lenA) {
                lenB --;
                b = b->next;
            }
        }
        while(a != b) {
            a = a->next;
            b = b->next;
        }
        ret = a;
        return ret;
    }
    //this is NOT memory O(1), utilize stack
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        stack<struct ListNode*> st1;
        stack<struct ListNode*> st2;
        struct ListNode * a = headA;
        struct ListNode * b = headB;
        struct ListNode * ret = nullptr; //same as NULL
        while(a) {
            st1.push(a);
            a = a->next;
        }
        while(b) {
            st2.push(b);
            b = b->next;
        }
        while(!st1.empty() && !st2.empty()) {
            if (st1.top() == st2.top()) {
                ret = st1.top();
                st1.pop();
                st2.pop();
            }
            else
                break;//first diff
        }
        return ret;
    }
};
