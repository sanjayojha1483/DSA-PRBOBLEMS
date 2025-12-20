class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* prevA = list1;
        for(int i = 0; i < a - 1; i++) {
            prevA = prevA->next;
        }

        ListNode* afterB = prevA;
        for(int i = a; i <= b; i++) {
            afterB = afterB->next;
        }
        afterB = afterB->next;

        prevA->next = list2;

        ListNode* temp = list2;
        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = afterB;

        return list1;
    }
};
