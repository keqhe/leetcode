
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = head;
        int total = 0;
        int todelete;
        int j = 0;
        while(start) {
            start = start->next;
            total ++;
        }
        todelete = total - n; // >= 0
        start = head;
        while (start) {
            if (todelete == 0) {//first
                struct ListNode *t = start;
                head = start->next;
                delete t;
                break;
            }
            else if (todelete - 1 == j) { 
                    struct ListNode *t = start->next;
                    start->next = start->next->next;
                    delete t;
                    break;
            }
            start = start->next;
            j ++;
        }
        return head;
    }
};
