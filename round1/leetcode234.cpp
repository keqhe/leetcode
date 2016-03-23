
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
    //this function reverses a linked list, and it chanegs its head
    void reverse(struct ListNode ** head_ref) {
        struct ListNode * current = *head_ref;
        struct ListNode * prev = nullptr;
        struct ListNode * next;
        while(current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *head_ref = prev;
    }
    
    bool compare2list(struct ListNode * p1, struct ListNode * p2) {
        while(p1 && p2) {
            if (p1->val == p2->val) {
                p1 = p1->next;
                p2 = p2->next;
            }
            else {
                return false;
            }
        }
        
        if (!p1 && !p2)
            return true;
        else
            return false;
    }
    //1->2
    
    //1->2->3 : odd
    //
    //1->2->3->4: even
    bool isPalindrome(ListNode* head) {
        struct ListNode * p1 = head;
        struct ListNode * p2 = head;
        struct ListNode * prev_p1 = nullptr;
        struct ListNode * mid = nullptr;
        struct ListNode * second = nullptr;
        bool res = true;// default true
        if (head && head->next) {//at least 2, otherwise must be true
            while(p2 && p2->next) {
                prev_p1 = p1;
                p1 = p1->next;
                p2 = p2->next->next;
            }
        
        
            if(p2) {
                mid = p1;
                p1 = p1->next;
            }
        
            second = p1; //start of second half;
            prev_p1->next = nullptr;
            reverse(&second);
            res = compare2list(head, second);
        
            //construct original list
            reverse(&second);
            if (mid) {
                prev_p1->next = mid;
                mid->next = second;
            }
            else {
                prev_p1->next = second;
            }
        }
        return res;
    }
    
    //use stack to reverse it, O(n) time complexity, O(n) space
    bool isPalindrome2(ListNode* head) {
        stack<int> s;
        ListNode * start = head;
        while(start) {
            int a = start->val;
            s.push(a);
            start = start->next;
        }
        
        start = head;
        while (start){
            int a = start->val;
            int b = s.top();
            if (a == b) {
                start = start->next;
                s.pop();
            }
            else 
                return false;
        }
        return true;
    }
};
