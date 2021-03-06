#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*problem: sort a linked list in O(nlogn), in place*/
struct ListNode {
	int val;
	struct ListNode * next;
	ListNode (int x) : val(x), next(NULL) {};
};

class Solution {
public:
    //merge two sorted list, similar as merge sort's merge function
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        struct ListNode * head = NULL;
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        struct ListNode * curr = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
        }
        if (l1)
            curr->next = l1;
        if (l2)
            curr->next = l2;
        return head;
    }
    //merge sort, ref: https://leetcode.com/discuss/73367/c-merge-sort-solution
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        struct ListNode * slow = head;
        struct ListNode * fast = head;
        struct ListNode * prev = NULL;
        //example, [1, 2]
        //[1,2,3]
        //[1,2,3,4]
        //while (slow && fast->next) { this is wrong
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev)
            prev->next = NULL;//terminate the first list;
        //slow points to the starting of the second list;
        struct ListNode * l1 = sortList(head);
        struct ListNode * l2 = sortList(slow);
        struct ListNode * nh = mergeTwoLists(l1, l2);
        return nh;
    }
};

void printList(struct ListNode* p) {
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
int main() {
	struct ListNode * p1 = new ListNode(5);
	struct ListNode * p2 = new ListNode(4);
	struct ListNode * p3 = new ListNode(3);
	struct ListNode * p4 = new ListNode(2);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	class Solution sn;
	struct ListNode * head = sn.sortList(p1);
	printList(head);
	return 0;	
}
