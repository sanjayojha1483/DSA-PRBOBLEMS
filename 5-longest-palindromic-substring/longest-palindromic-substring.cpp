class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0;   // answer substring ka start index
        int maxLen = 1;  // answer ki length

        for (int i = 0; i < n; i++) {

            // ---- Odd length palindrome ----
            int left = i;
            int right = i;

            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    start = left;
                    maxLen = len;
                }
                left--;
                right++;
            }

            // ---- Even length palindrome ----
            left = i;
            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    start = left;
                    maxLen = len;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};
