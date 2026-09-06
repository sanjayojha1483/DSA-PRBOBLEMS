class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int ans = 0;

        // First window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }

        ans = count;

        // Slide the window
        for (int i = k; i < s.length(); i++) {

            // Add the new character
            if (isVowel(s[i])) {
                count++;
            }

            // Remove the character leaving the window
            if (isVowel(s[i - k])) {
                count--;
            }

            ans = max(ans, count);
        }

        return ans;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }
};