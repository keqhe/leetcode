
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
    ListNode *merge2Lists(ListNode* head1, ListNode* head2) {
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        ListNode * newhead = nullptr;
        ListNode * prev = nullptr;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                if (!newhead) {
                    newhead = head1;
                    prev = newhead;
                }
                else {
                    prev->next = head1;
                    prev = head1;
                }
                head1 = head1->next;
            }
            else {
                if (!newhead) {
                    newhead = head2;
                    prev = newhead;
                }
                else {
                    prev->next = head2;
                    prev = head2;
                }
                head2 = head2->next;
            }
        }
        if (head1) {
            if (prev)
                prev->next = head1;
            else
                newhead = head1;
        }
        if (head2) {
            if (prev)
                prev->next = head2;
            else
                newhead = head2;
        }
        return newhead;
    }
    ListNode* helper(vector<ListNode*>& lists, int l, int r) {
        if (l == r)
            return lists[l];
        else if (l < r) {
            int m = l + (r-l)/2;
            ListNode * l1 = helper(lists, l, m);
            ListNode * l2 = helper(lists, m+1, r);
            ListNode * l = merge2Lists(l1, l2);
            return l;
        }
        else
            return nullptr;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        
        return helper(lists, 0, lists.size()-1);
    }
};
