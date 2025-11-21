class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        int need[256] = {0};
        int window[256] = {0};

        // Step 1: Count needed characters
        for (int i = 0; i < t.size(); i++) {
            need[t[i]]++;
        }

        int have = 0;
        int required = t.size();
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        // Step 2: Sliding window on s
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            // If this char was needed and still needed, we increase "have"
            if (need[c] > 0 && window[c] <= need[c]) {
                have++;
            }

            // When full match mil jaye
            while (have == required) {
                // Update answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Window shrink from left
                char leftChar = s[left];
                window[leftChar]--;
                if (need[leftChar] > 0 && window[leftChar] < need[leftChar]) {
                    have--;
                }
                left++;
            }
        }

        if (minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};
