class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Check cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // 1 step
            fast = fast->next->next;    // 2 steps

            if (slow == fast) {          // cycle found
                // Step 2: find starting node
                ListNode* start = head;

                while (start != slow) {
                    start = start->next;
                    slow = slow->next;
                }
                return start;
            }
        }

        return NULL; // no cycle
    }
};
