
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        struct ListNode *nh = NULL;
        struct ListNode * curr = head;
        struct ListNode * next = NULL;
        struct ListNode * prev = NULL;
        //while (curr->next) {//this is WRONG!
        while (curr && curr->next) {//this is correct
            next = curr->next;
            cout << "curr: " << curr->val << " " << next->val << endl;
            if (!nh) {
                nh = next;
            }
            if (prev) {
                prev->next = next;
            }

            curr->next = next->next;
            next->next = curr;
            prev = curr;
            curr = curr->next;
        }
        prev = NULL;
        return nh;
    }
};
