#include<iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        struct ListNode* h1 = head;
        struct ListNode* h2 = head->next;
        
        struct ListNode * h1_head = h1;
        struct ListNode * h2_head = h2;
        
        struct ListNode* curr = h2->next;
        int count = 0;
        while (curr) {
            count ++;
            //cout << count << " ";
            if (count % 2 == 1) {
                h1->next = curr;
                h1 = h1->next;
                //cout << curr->val << endl;
                curr = curr->next;
            }
            else {
                h2->next = curr;
                h2 = h2->next;
                //cout << curr->val << endl;
                curr = curr->next;
            }
        }
        h1->next = NULL;
        h2->next = NULL;
        
        h1 = h1_head;
        h2 = h2_head;
        
        struct ListNode * dummy = new ListNode(0);
        curr = dummy;
        count = 0;
        while (h1 && h2) {
            if (count % 2 == 0) {
                curr->next = h2;
                h2 = h2->next;
            }
            else {
                curr->next = h1;
                h1 = h1->next;
            }
            curr = curr->next;
            count ++;
        }
        curr->next = h1;
        
        return dummy->next;
    }
};

int main() {
	class Solution sn;
	return 0;
}
