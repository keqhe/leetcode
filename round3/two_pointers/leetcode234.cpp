
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
    //using stack is the first method
    //the second method is to split the list into 2 and reverse the second part and check
    struct ListNode * reverse(struct ListNode * head) {
        if (!head || !head->next)
            return head;
        struct ListNode * prev = NULL;
        struct ListNode * curr = head;
        while (curr) {
            struct ListNode * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool compare(struct ListNode * p1, struct ListNode * p2) {
        while (p1 && p2) {
            if (p1->val != p2->val)
                return false;
            else {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return (!p1) && (!p2);
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        struct ListNode * slow = head;
        struct ListNode * fast = head;
        struct ListNode * prev = NULL;
        struct ListNode * mid = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        struct ListNode *l1 = NULL;
        struct ListNode *l2 = NULL;
        if (fast) {//1->2->3
            mid = slow;
            l1 = head;
            l2 = mid->next;
            prev->next = NULL;
            l2 = reverse(l2);
        }
        else {//1->2
            mid = NULL;
            l1 = head;
            l2 = slow;
            prev->next = NULL;
            l2 = reverse(l2);
        }
        return compare(l1, l2);
    }
};
