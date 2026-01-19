/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKNodes(ListNode* head, int k, ListNode** nextNode) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        int count = 0;

        while (curr != NULL && count < k) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        *nextNode = curr;   // next group ka start point
        return prev;        // reversed group ka new head
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* curr = head;
        int count = 0;

        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        if (count < k) return head;

        ListNode* nextNode = NULL;
        ListNode* newHead = reverseKNodes(head, k, &nextNode);

        head->next = reverseKGroup(nextNode, k);

        return newHead;
    }
};
