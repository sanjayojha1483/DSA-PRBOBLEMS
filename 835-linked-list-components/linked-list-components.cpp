class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());
        int count = 0;

        while (head) {
            if (st.count(head->val) &&
                (head->next == NULL || !st.count(head->next->val))) {
                count++;
            }
            head = head->next;
        }
        return count;
    }
};
