class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        stack<Node*> st;
        Node* curr = head;

        while (curr) {
            if (curr->child) {
                if (curr->next)
                    st.push(curr->next);

                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
            }

            if (!curr->next && !st.empty()) {
                Node* top = st.top(); st.pop();
                curr->next = top;
                top->prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};
