
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
    bool compareList(struct ListNode * l1, struct ListNode * l2) {
        if (!l1 && !l2)
            return true;
        if (!l1 || !l2)
            return false;
        while (l1 && l2) {
            if (l1->val == l2->val) {
                l1 = l1->next;
                l2 = l2->next;
            }
            else
                return false;
        }
        if (l1 || l2)
            return false;
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        struct ListNode * prev = NULL;
        while (head) {
            struct ListNode * p = head;
            head = head->next;
            p->next = prev;
            prev = p;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)   
            return true;
        struct ListNode * fast = head;
        struct ListNode * slow = head;
        struct ListNode * prev = NULL;
        struct ListNode * mid = NULL;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //[1,2,3]
        //or [1,2,3,4]
        if (fast) {//odd
            mid = slow;
            prev->next = NULL;
            struct ListNode * l2 = mid->next;
            l2 = reverseList(l2);
            return compareList(head, l2);
        }
        else {//even
            prev->next = NULL;
            struct ListNode * l2 = slow;
            l2 = reverseList(l2);
            return compareList(head, l2);
        }
    }
};
