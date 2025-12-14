class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* odd = head;          // 1st node
        ListNode* even = head->next;   // 2nd node
        ListNode* evenHead = even;     // even list ka start

        while (even != NULL && even->next != NULL) {
            odd->next = even->next;    // odd ko next odd se jodo
            odd = odd->next;

            even->next = odd->next;    // even ko next even se jodo
            even = even->next;
        }

        odd->next = evenHead;          // odd list ke end me even list jod do
        return head;
    }
};
