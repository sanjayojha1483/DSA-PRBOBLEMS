class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) return ans;

        int freqP[26] = {0};
        int freqS[26] = {0};

        // count p characters
        for (int i = 0; i < p.size(); i++) {
            freqP[p[i] - 'a']++;
        }

        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            // add right character
            freqS[s[r] - 'a']++;

            // window size bada ho gaya
            if (r - l + 1 > p.size()) {
                freqS[s[l] - 'a']--;
                l++;
            }

            // check anagram
            if (r - l + 1 == p.size()) {
                if (isSame(freqS, freqP)) {
                    ans.push_back(l);
                }
            }
        }
        return ans;
    }

    bool isSame(int a[], int b[]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};
