
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
    //[1,2,5], [3,4]
    void merge(struct ListNode* h1, struct ListNode * h2) {//len(h1) >= len(h2)
        //cout << h1->val << ' ' << h1->next->val << endl;
        //cout << h2->val << ' ' << h2->next->val << endl;
        struct ListNode * curr = NULL;
        int iter = 0;
        while (h1 && h2) {
            if (iter % 2 == 0) {
                if (iter == 0) {
                    curr = h1;
                }
                else {
                    curr->next = h1;
                    curr = curr->next;
                }
                h1 = h1->next;
            }
            else {
                curr->next = h2;
                curr = curr->next;
                h2 = h2->next;
            }
            iter ++;
        }
        if (h1)
            curr->next = h1;
        if (h2)
            curr->next = h2;
    }
    struct ListNode* reverse(struct ListNode * head) {//[1,2,3]
        struct ListNode * curr = NULL;
        struct ListNode * p = head;
        while (p) {
            struct ListNode * next = p->next;
            p->next = curr;
            curr = p;
            p = next;
        }
        return curr;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
        struct ListNode * fast = head;
        struct ListNode * slow = head;
        struct ListNode * prev = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        //[1,2,3,4]
        //[1,2,3]
        struct ListNode * l2;
        struct ListNode * l1;
        if (fast) {//odd, 
           l2 = slow->next;
           l1 = head;
           slow->next = NULL;
        }
        else {//even
            l2 = slow;
            l1 = head;
            prev->next = NULL;
        }
        //cout << l2->val << ' ' << l2->next->val << endl;
        l2 = reverse(l2);
        //cout << l2->val << ' ' << l2->next->val << endl;
        merge(l1, l2);
    }
    //below are Time Limite Exceeded version
    struct ListNode * handleLast (struct ListNode * start) {//if start is NULL or start->next is NULL, return NULL;
        if (!start)
            return NULL;
        struct ListNode * p = start;
        struct ListNode * prev = start;
        while (p->next) {
            prev = p;
            p = p->next;
        }
        p = prev->next;
        prev->next = NULL;
        return p;
    }
    void reorderList_TLE(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
        struct ListNode * p1 = head;
        struct ListNode * p2 = NULL;
        while (p1) {
            struct ListNode * last = handleLast(p1->next);//think about 1->2->3->4
           
            if (last) {
                //cout << last->val << endl;
                p2 = p1->next;
                p1->next = last;
                last->next = p2;
                p1 = p2;
                //if (p1)
                //    cout << p1->val << endl;
            }
            else {
                //cout << "break..." << endl;
                break;//done
            }
        }
    }
};
