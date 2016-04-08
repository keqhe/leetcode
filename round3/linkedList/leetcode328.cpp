
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        struct ListNode * h1 = head;
        struct ListNode * h2 = head->next;
        struct ListNode * curr1 = h1; 
        struct ListNode * curr2 = h2;
        struct ListNode * curr = h2->next;
        int cnt = 0;
        while (curr) {
            cnt ++;
            if (cnt % 2 == 1) {//odd
               curr1->next = curr;
               curr1 = curr;
            }
            else {//even
                curr2->next = curr;
                curr2 = curr;
            }
            curr = curr->next;
        }
        curr2->next = NULL;//initially forgot this!
        curr1->next = h2;
        return h1;
    }
};
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        struct ListNode * h1 = head;
        struct ListNode * h2 = head->next;
        struct ListNode * curr1 = h1; 
        struct ListNode * curr2 = h2;
        struct ListNode * curr = h2->next;
        int cnt = 0;
        while (curr) {
            cnt ++;
            if (cnt % 2 == 1) {//odd
               curr1->next = curr;
               curr1 = curr;
            }
            else {//even
                curr2->next = curr;
                curr2 = curr;
            }
            curr = curr->next;
        }
        curr2->next = NULL;//initially forgot this!
        curr1->next = h2;
        return h1;
    }
};
