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
    //revervoir sampling
    //for 1..k, put it into the reservoir
    //for k+i (i >=1 and k+i <= n), take probability p = k/(k+i) and replace (k+i)th element with a random choosen element in the revervoir with probability p.
    //the prability that X is selected before (k+i) * the probability that X is not replaced.
    // k / (k+i-1) * (1  - k/(k+i) * 1/k)
    //= k / (k+i), when k+i reach n, the probability that each element stays in the reservoir is k/n;
    // ref: https://discuss.leetcode.com/topic/53753/brief-explanation-for-reservoir-sampling
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode * head;
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        auto p = head;
        int x = p->val;
        int count = 1;
        while (p) {
            p = p->next;
            count ++;
            if (p) {
                int r = random() % count;
                if (r == 0) {
                    x = p->val;
                }
            }
        }
        return x;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
