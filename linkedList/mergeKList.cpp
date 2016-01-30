#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
	int val;
	struct ListNode * next;
	ListNode(int x) : val(x), next(NULL){};
};

class Solution {
public:
    //two ideas, the first is call mergeTwoLists, 
    //first idea: call mergeTwoLists: T(n) = 2T(n/2) + O(2m)
    //if m = theta(n), then time complexity is O(nlogn)
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
    struct ListNode * helper(vector<ListNode*> & lists, int left, int right) {
        if (left > right)
            return NULL;
        else if (left == right)
            return lists[left];
        else if (left < right) {
            int mid = left + (right - left)/2;
            struct ListNode * l = helper(lists, left, mid);
            struct ListNode * r = helper(lists, mid+1, right);
            return mergeTwoLists(l, r);
        }
    }
    ListNode* mergeKLists_idea1(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        return helper(lists, 0, lists.size()-1);
    }
    //using priority_queue, ref: https://leetcode.com/discuss/72999/concise-c-solution-priority_queue
    /*bool mycmp(struct ListNode * p1, struct ListNode * p2) {
        return p1->val < p2->val;
    }*/ //for priority, the last parameter must be a class "cmp"
    class myCmp {
    public:
        bool operator() (struct ListNode * p1, struct ListNode * p2) {
            return p1->val > p2->val;
        }//we want to smallest element appear at the top(), so use ">",  or std::greater<int>
        //default, priority_queue has the largest element appear at the top()
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        priority_queue<struct ListNode*, vector<struct ListNode*>, myCmp> priQ;
        for (int i = 0; i < lists.size(); i ++)
            if (lists[i]) {
                priQ.push(lists[i]);
            }
        cout << "debug..." << endl;
        struct ListNode * nh = new ListNode(0);
        struct ListNode * curr = nh;
        while (!priQ.empty()) {
            struct ListNode * p = priQ.top();
            curr->next = p;
            p = p->next;
            priQ.pop();
            if (p)
                priQ.push(p);
            curr = curr->next;
        }
        
        return nh->next;
    }
};

int main() {
	class Solution sn;
	vector<struct ListNode*> v;
	struct ListNode * p = sn.mergeKLists(v);
	return 0;
}
