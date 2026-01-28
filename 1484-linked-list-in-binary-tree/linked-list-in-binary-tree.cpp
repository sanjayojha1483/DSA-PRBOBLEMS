class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) return true;        // linked list fully matched
        if (!root) return false;       // tree ended early
        if (head->val != root->val) return false;

        return dfs(head->next, root->left) ||
               dfs(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;

        return dfs(head, root) ||
               isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }
};
