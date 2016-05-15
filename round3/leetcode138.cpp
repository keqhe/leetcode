
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
    //method 1: hash tables
    RandomListNode *copyRandomList_m1(RandomListNode *head) {
        if (!head)
            return NULL;
        unordered_map<struct RandomListNode*, struct RandomListNode*> m;
        struct RandomListNode * curr = head;
        struct RandomListNode * prev = NULL;
        struct RandomListNode * nh = NULL;
        while (curr) {
            struct RandomListNode * tmp = new RandomListNode(curr->label);
            m[curr] = tmp;
            if (!nh) {
                nh = tmp;
                prev = nh;
            }
            else {
                prev->next = tmp;
                prev = tmp;
            }
            curr = curr->next;
        }
        
        curr = head;
        while (curr) {
            struct RandomListNode * old_random = curr->random;
            struct RandomListNode * new_node = m[curr];
            if (!old_random) {
                new_node->random = NULL;
            }
            else {
                new_node->random = m[old_random];
            }
            curr = curr->next;
        }
        return nh;
    }
    //method 2
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
        struct RandomListNode * curr = head;
        //duplicate each node in the linked list
        while (curr) {
            struct RandomListNode * next = curr->next;
            struct RandomListNode * tmp = new RandomListNode(curr->label);
            tmp->next = next;
            curr->next = tmp;
            curr = next;
        }
        //assign the random pointers in each node
        curr = head;
        while (curr) {
            struct RandomListNode * new_node = curr->next;
            if (curr->random == NULL)
                new_node->random = NULL;
            else
                new_node->random = curr->random->next;
            curr = new_node->next;
        }
        //split the list into two
        struct RandomListNode * nh = NULL;
        struct RandomListNode * prev = nh;
        int cnt = 0;
        curr = head;
        while(curr) {
            struct RandomListNode * new_node = curr->next;
            curr->next = new_node->next;
            if (!nh) {
                nh = new_node;
                prev = nh;
            }
            else {
                prev->next = new_node;
                prev = new_node;
            }
            curr = curr->next;
        }
        prev->next = NULL;
        return nh;
    }
};
