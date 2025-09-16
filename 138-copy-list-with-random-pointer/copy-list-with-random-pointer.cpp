class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> mp;

        // Step 1: Copy all nodes (values only)
        Node* curr = head;
        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Step 2: Assign next and random
        curr = head;
        while (curr) {
            mp[curr]->next = mp[curr->next];       // may be nullptr
            mp[curr]->random = mp[curr->random];   // may be nullptr
            curr = curr->next;
        }

        return mp[head];
    }
};
