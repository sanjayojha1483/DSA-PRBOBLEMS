class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int len = 0;

        // Step 1: length nikaalo
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        // Step 2: kth from start
        ListNode* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // Step 3: kth from end
        ListNode* second = head;
        for (int i = 1; i < len - k + 1; i++) {
            second = second->next;
        }

        // Step 4: swap values
        int t = first->val;
        first->val = second->val;
        second->val = t;

        return head;
    }
};
