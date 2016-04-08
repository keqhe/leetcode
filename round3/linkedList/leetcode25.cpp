
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
    //two solutions, recursion and deque
    
    //method 1, recursion
    struct ListNode *reverseList(struct ListNode * start, struct ListNode * end) {
        if (!start)
            return NULL;
        if (start == end)
            return start;
        struct ListNode * prev = NULL;
        struct ListNode * curr = start;
        while (curr != end) {
            struct ListNode * n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }
    ListNode* reverseKGroup_recursion(ListNode* head, int k) {
        if (!head || !head->next || k == 1)
            return head;
        struct ListNode * curr = head;
        for (int i = 0; i < k; i ++) {//1->2->3->4
            if (curr == NULL)
                return head;//no enough for reverse
            else 
                curr = curr->next;
        }
        struct ListNode * nh = reverseList(head, curr);
        head->next = reverseKGroup(curr, k);
        return nh;
    }
    //method 2, deque
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 1)
            return head;
        deque<struct ListNode *> de;
        struct ListNode * curr = head;
        struct ListNode * prev = NULL;
        struct ListNode * nh = NULL;
        while (curr) {
            struct ListNode * next = curr->next;
            if (de.size() < k) {
                de.push_back(curr);
            }
            if (de.size() == k) {
                while (!de.empty()) {
                    if (!nh) {
                        nh = de.back();
                        prev = nh;
                        de.pop_back();
                    }
                    else {
                        prev->next = de.back();
                        prev = de.back();
                        de.pop_back();
                    }
                }
            }
            curr = next;
        }
        //leftover
        if (de.size() < k) {
            while (!de.empty()) {
                if (!nh) {
                    nh = de.front();
                    prev = nh;
                    de.pop_front();
                }
                else {
                    prev->next = de.front();
                    prev = de.front();
                    de.pop_front();
                }
            }
            prev->next = NULL;//end the list
        }
        else if (de.size() == k) {
            while (!de.empty()) {
                    if (!nh) {
                        nh = de.back();
                        prev = nh;
                        de.pop_back();
                    }
                    else {
                        prev->next = de.back();
                        prev = de.back();
                        de.pop_back();
                    }
            }
            prev->next = NULL;
        }
        return nh;
    }
};

