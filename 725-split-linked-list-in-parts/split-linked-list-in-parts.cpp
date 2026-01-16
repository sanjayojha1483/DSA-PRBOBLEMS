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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        int n = 0;
        
        // Step 1: Count length
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        int base = n / k;     // Har part ki minimum size
        int extra = n % k;    // Extra nodes

        temp = head;
        for (int i = 0; i < k; i++) {
            ans[i] = temp;   // Store head of current part
            int size = base + (extra > 0 ? 1 : 0);
            if (extra > 0) extra--;

            // Move pointer size-1 times
            for (int j = 0; j < size - 1 && temp; j++) {
                temp = temp->next;
            }

            // Cut the list
            if (temp) {
                ListNode* nextHead = temp->next;
                temp->next = nullptr;
                temp = nextHead;
            }
        }
        return ans;
    }
};
