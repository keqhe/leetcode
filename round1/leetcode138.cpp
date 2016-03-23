
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    //for each node, create a duplicated node, then copy random pointer, then decouple the list
    //see, http://fisherlei.blogspot.com/2013/11/leetcode-copy-list-with-random-pointer.html
    //O(n) time complexity and O(1) space complexity
    RandomListNode *copyRandomList_duplicate(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        struct RandomListNode *p1 = head;
        struct RandomListNode * newhead = NULL;
        struct RandomListNode *p2 = NULL;
        while (p1) {
            struct RandomListNode *p1_nxt = p1->next;
            p2 = new RandomListNode(p1->label);
            if (p1 == head)
                newhead = p2;
            p1->next = p2;
            p2->next = p1_nxt;
            p1 = p1_nxt;
        }
        
        //copy random pointers
        p1 = head;
        p2 = newhead;
        while (p1) {
            if (p1->random)
                p2->random = p1->random->next;
            else
                p2->random = NULL;
            
            p1 = p2->next;
            if (p1)
                p2 = p1->next;
            else
                p2 = NULL;
        }
        
        //decouple
        p1 = head;
        p2 = newhead;
        //think about the example of 1 2
        while (p1) {
            p1->next = p2->next;
            p1 = p1->next;
            if (p1) {
                p2->next = p1->next;
                p2 = p2->next;
            }
        }
        
        return newhead;
    }
    //there is a much simpler solution which uses hash table
    //see, http://blog.csdn.net/linhuanmars/article/details/22463599
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        unordered_map<struct RandomListNode*, struct RandomListNode *> m; //<old, new>
        struct RandomListNode *p1;
        struct RandomListNode * newhead = new RandomListNode(head->label);
        struct RandomListNode *p2 = newhead;
        
        p1 = head->next;
        m[head] = newhead;
        while(p1) {
            struct RandomListNode * n = new RandomListNode(p1->label);
            p2->next = n;
            m[p1] = n;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        p1 = head;
        p2 = newhead;
        while (p1) {
            p2->random = m[p1->random];
            p1 = p1->next;
            p2 = p2->next;
        }
        return newhead;
    }
    //below is my initial thoughts on this problem. Others have better solutions
    RandomListNode *copyRandomList_mine(RandomListNode *head) {
        struct RandomListNode * newhead = NULL;
        if (head == NULL)
            return NULL;
            
        if (head) {
            newhead = new RandomListNode(head->label);
        }
        struct RandomListNode * p1 = head->next;
        struct RandomListNode * p2 = newhead;
        while (p1) {
            p2->next = new RandomListNode(p1->label);
            p1 = p1->next;
            p2 = p2->next;
        }
        
        //hash table
        unordered_map<struct RandomListNode *, int> m1; //<pointer, position>
        p1 = head;
        int i = 1;
        while(p1) {
            m1[p1] = i;
            i ++;
            p1 = p1->next;
        }
        unordered_map<int, int> m2;//<position, position>
        p1 = head;
        i = 1;
        while(p1) {
            struct RandomListNode * r = p1->random;
            if (r == NULL)
                m2[i] = -1;
            else
                m2[i] = m1[r];
            i ++;
            p1 = p1->next;
        }
        //cloned list
        unordered_map<int, struct RandomListNode *> m3;//<int, pointer>
        int j = 1;
        p2 = newhead;
        while (p2) {
            m3[j] = p2;
            j ++;
            p2 = p2->next;
        }
        
        //assign
        p2 = newhead;
        j = 1;
        while(p2) {
            int t = m2[j];
            if (t == -1)
                p2->random = NULL;
            else
                p2->random = m3[t];
            j ++;
            p2 = p2->next;
        }
        
        //return
        return newhead;
    }
};
