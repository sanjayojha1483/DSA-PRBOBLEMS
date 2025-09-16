class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Step 1: Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Move prev to the node before 'left'
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 3: Reverse sublist from left to right
        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        ListNode* reversePrev = nullptr;

        for (int i = 0; i <= right - left; i++) {
            next = curr->next;
            curr->next = reversePrev;
            reversePrev = curr;
            curr = next;
        }

        // Step 4: Reconnect
        prev->next->next = curr;   // tail of reversed sublist points to remaining list
        prev->next = reversePrev;  // prev points to new head of sublist

        return dummy->next;
    }
};
