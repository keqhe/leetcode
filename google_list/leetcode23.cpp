
class Solution {
public:
    //T(n) = aT(n/b) + f(n)
    //find the relationship of n^((log_b)^a)
    //T(m) = 2T(m/2) + O(n)
    // assume that m = n
    // (log_b)^a = 1
    // so time complexity is O(nlogn)
    ListNode * merge2Lists(ListNode *head1, ListNode* head2) {
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        ListNode * newhead = nullptr;
        ListNode * prev = nullptr;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                auto curr = head1;
                head1 = head1->next;
                if (!prev) {
                    newhead = curr;
                    prev = curr;
                }
                else {
                    prev->next = curr;
                    prev = curr;
                }
            }
            else {
                auto curr = head2;
                head2 = head2->next;
                if (!prev) {
                    newhead = curr;
                    prev = curr;
                }
                else {
                    prev->next = curr;
                    prev = curr;
                }
            }
        }
        if (head1)
            prev->next = head1;
        else if (head2)
            prev->next = head2;
        else
            prev->next = NULL;
        return newhead;
    }
    ListNode * helper(vector<ListNode*>& lists, int l, int r) {
        if (l > r)
            return nullptr;
        if (l == r)
            return lists[l];
        int mid = l + (r-l)/2;
        auto l1 = helper(lists, l, mid);
        auto l2 = helper(lists, mid+1, r);
        return merge2Lists(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(lists, 0, lists.size()-1);
    }
};
