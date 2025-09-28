class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);       // last index of each char
        vector<bool> used(26, false);  // if char already in result

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;      // store last occurrence
        }

        string st = ""; // use string like a stack

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (used[c - 'a']) continue; // skip if already in result

            // while top of stack is bigger than current char
            // and top will appear again later, pop it
            while (!st.empty() && st.back() > c && last[st.back() - 'a'] > i) {
                used[st.back() - 'a'] = false; // mark popped char as unused
                st.pop_back();
            }

            st.push_back(c);            // add current char
            used[c - 'a'] = true;       // mark as used
        }

        return st; // result is already built
    }
};
