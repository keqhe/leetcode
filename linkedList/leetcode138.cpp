#include<iostream>
#include<unordered_map>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode * next, *random;
	RandomListNode (int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    //two solutions to solve this problem, hash table or duplicates each node
    //1. hash table
    RandomListNode *copyRandomList_hashtable(RandomListNode *head) {
        if (!head)
            return NULL;
        unordered_map<struct RandomListNode*, struct RandomListNode*> m1;//curr to random
        unordered_map<struct RandomListNode*, struct RandomListNode*> m2;//old to new
        m2[NULL] = NULL;
        
        struct RandomListNode * curr = head;
        struct RandomListNode * newhead = NULL;
        struct RandomListNode * newCurr = NULL;
        while (curr) {
            m1[curr] = curr->random;
            if (!newhead) {
                newhead = new RandomListNode(curr->label);
                newCurr = newhead;
                m2[curr] = newCurr;
            }
            else {
                newCurr->next = new RandomListNode(curr->label);
                newCurr = newCurr->next;
                m2[curr] = newCurr;
            }
            curr = curr->next;
        }
        newCurr->next = NULL;
        curr = newhead;
        struct RandomListNode * tmp = head;
        while (curr) {
            struct RandomListNode * r =  m2[m1[tmp]];
            curr->random = r;
            curr = curr->next;
            tmp = tmp->next;
        }
        
        return newhead;
    }
    //2.duplicate each node
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
        struct RandomListNode * curr = head;
        while (curr) {
            struct RandomListNode * newp = new RandomListNode(curr->label);
            struct RandomListNode * tmp = curr->next;
            curr->next = newp;
            newp->next = tmp;
            curr = tmp;
        }
        cout << "debug1" << endl;
        curr = head;
        int count = 0;
        while (curr) {
            count ++;
            if (count % 2 == 1) {//old list
                struct RandomListNode * tmp = curr->next;
                if (curr->random)
                    tmp->random = curr->random->next;//key is here
                else
                    tmp->random = NULL;
            }
            curr = curr->next;
        }
        cout << "debug2" << endl;
        //split two lists
        struct RandomListNode * newhead = head->next;
        struct RandomListNode * p1 = head;
        struct RandomListNode * p2 = newhead;
        curr = newhead->next;
        count = 0;
        while (curr) {
            count ++;
            if (count % 2 == 1) {//old list
                p1->next = curr;
                curr = curr->next;
                p1 = p1->next;
            }
            else {
                p2->next = curr;
                curr = curr->next;
                p2 = p2->next;
            }
        }
        
        p1->next = NULL;
        p2->next = NULL;
        
        return newhead;
    }
};

int main() {
	class Solution sn;
	return 0;
}
