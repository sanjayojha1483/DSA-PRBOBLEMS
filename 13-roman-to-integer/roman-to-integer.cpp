class Solution {
public:
    int romanToInt(string s) {
        // fixed-size map → O(1) space
        int values[128]; // ASCII-based lookup
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100;
        values['D'] = 500;
        values['M'] = 1000;

        int result = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            // if current < next → subtract
            if (i + 1 < n && values[s[i]] < values[s[i + 1]]) {
                result -= values[s[i]];
            } else {
                result += values[s[i]];
            }
        }
        return result;
    }
};
