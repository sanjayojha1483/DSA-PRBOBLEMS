class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency using array (simple)
        int freq[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        // Step 2: Make a new string for sorting
        vector<pair<int, char>> arr;

        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                arr.push_back({freq[i], (char)i});
            }
        }

        // Step 3: Sort by frequency (bada wala number pehle)
        sort(arr.begin(), arr.end());

        // Step 4: Build answer string (reverse because sort ascending hoti hai)
        string ans = "";
        for (int i = arr.size() - 1; i >= 0; i--) {
            for (int j = 0; j < arr[i].first; j++) {
                ans += arr[i].second;
            }
        }

        return ans;
    }
};

// i am not sure to i can do it by myself