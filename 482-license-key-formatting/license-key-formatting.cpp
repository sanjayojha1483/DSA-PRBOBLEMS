class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean = "";
        for (char c : s) {
            if (c != '-') clean += toupper(c);
        }

        string result = "";
        int count = 0;

        for (int i = clean.size() - 1; i >= 0; i--) {
            result.push_back(clean[i]);
            count++;
            if (count == k && i != 0) {
                result.push_back('-');
                count = 0;
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

