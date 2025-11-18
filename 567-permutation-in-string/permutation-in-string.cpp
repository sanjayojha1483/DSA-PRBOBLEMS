class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int need[26] = {0};
        int window[26] = {0};

        // Step 1: Count s1 characters
        for (int i = 0; i < s1.size(); i++) {
            need[s1[i] - 'a']++;
        }

        int k = s1.size();

        // Step 2: first window of s2
        for (int i = 0; i < k; i++) {
            window[s2[i] - 'a']++;
        }

        // Step 3: Check first window
        bool same = true;
        for (int i = 0; i < 26; i++) {
            if (need[i] != window[i]) {
                same = false;
                break;
            }
        }
        if (same) return true;

        // Step 4: Slide the window
        for (int i = k; i < s2.size(); i++) {

            // remove old char
            window[s2[i - k] - 'a']--;

            // add new char
            window[s2[i] - 'a']++;

            // compare arrays
            bool ok = true;
            for (int j = 0; j < 26; j++) {
                if (need[j] != window[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }

        return false;
    }
};
