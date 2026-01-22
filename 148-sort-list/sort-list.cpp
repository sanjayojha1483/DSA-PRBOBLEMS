class Solution {
public:
    // 🔹 Merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);          // temporary node
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // attach remaining nodes
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    // 🔹 Find middle of linked list
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 🔹 Main function
    ListNode* sortList(ListNode* head) {
        // base case
        if (!head || !head->next)
            return head;

        // 1️⃣ find middle
        ListNode* mid = getMid(head);

        // 2️⃣ split list
        ListNode* right = mid->next;
        mid->next = NULL;

        // 3️⃣ sort both halves
        ListNode* left = sortList(head);
        right = sortList(right);

        // 4️⃣ merge sorted halves
        return merge(left, right);
    }
};
