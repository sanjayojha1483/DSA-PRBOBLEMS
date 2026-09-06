class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        int count = 0;

        // First window
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) {
                count++;
            }
        }

        int ans = count;

        // Slide window
        for (int i = k; i < s.size(); i++) {

            // Add new character
            if (vowels.count(s[i])) {
                count++;
            }

            // Remove old character
            if (vowels.count(s[i - k])) {
                count--;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};