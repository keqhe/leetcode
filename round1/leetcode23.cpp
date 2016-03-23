
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
    //this one looks easier to understand
    //https://leetcode.com/discuss/68414/c-solution-using-merge-sort
    //what's the time complexity?
    struct ListNode* mergeTwoList(struct ListNode*l1, struct ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoList(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoList(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end) {
        if (start == end)
            return lists[start];
        else if (start > end)
            return NULL;
        else {
            int mid = start + (end-start)/2;
            struct ListNode * l = mergeKLists(lists, start, mid);
            struct ListNode * r = mergeKLists(lists, mid+1, end);
            return mergeTwoList(l, r);
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }
};
