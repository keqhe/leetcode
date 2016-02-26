#include<iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode * next;
	ListNode(int x) {
		val = x;
		next = NULL;
	}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)
            return head;
        struct ListNode * less = NULL;
        struct ListNode * more = NULL;
        
        struct ListNode * less_head = NULL;
        struct ListNode * more_head = NULL;
        
        
        struct ListNode * curr = head;
        while (curr) {
            if (curr->val < x) {
                if (!less) {
                    less = curr;
                    less_head = less;
                }
                else {
                    less->next = curr;
                    less = less->next;
                }
            }
            else {
                if (!more) {
                    more = curr;
                    more_head = more;
                }
                else {
                    more->next = curr;
                    more = more->next;
                }
            }
            curr = curr->next;
        }
        if (more)
            more->next = NULL;
        if (less)
            less->next = more_head;
        else
            less_head = more_head;
        return less_head;
    }
};

int main() {
	class Solution sn;
	return 0;
}
