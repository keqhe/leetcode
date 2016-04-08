
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
    //time complexity is T(n) = 2T(n/2) + O(k), where n is the number of lists and k is number of elements in each lists
    //master theorm: T(n) = aT(n/b) + f(n), n^((log_b)^a) =(n^1)=n. f(n) = O(k)
    //if O(k) == O(n), then time complexity is O(nlogn)
    //if O(k) < O(n), then time complexity is O(n)
    //if O(k) > O(n), then time complexity is O(k)
    struct ListNode * merge2Lists(struct ListNode * head1, struct ListNode * head2) {
        if (!head1 && !head2)
            return nullptr;
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        struct ListNode * nh = NULL;
        struct ListNode * prev = NULL;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                if (!nh) {
                    nh = head1;
                    prev = nh;
                    head1 = head1->next;
                }
                else {
                    prev->next = head1;
                    prev = head1;
                    head1 = head1->next;
                }
            }
            else {
                if (!nh) {
                    nh = head2;
                    prev = nh;
                    head2 = head2->next;
                }
                else {
                    prev->next = head2;
                    prev = head2;
                    head2 = head2->next;
                }
            }
        }
        if (head1)
            prev->next = head1;
        if (head2) 
            prev->next = head2;
        return nh;
    }
    struct ListNode * helper(vector<struct ListNode*>& lists, int left, int right) {
        if (left > right)
            return NULL;
        if (left == right)
            return lists[left];
        int mid = left + (right-left)/2;
        struct ListNode * first = helper(lists, left, mid);
        struct ListNode * second = helper(lists, mid+1, right);
        return merge2Lists(first, second);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        return helper(lists, 0, lists.size()-1);
    }
};
