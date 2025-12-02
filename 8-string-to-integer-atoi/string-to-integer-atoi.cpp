class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        
        // Step 1: skip spaces
        while (i < n && s[i] == ' ')
            i++;

        // Step 2: check sign
        int sign = 1;
        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        } else if (i < n && s[i] == '+') {
            i++;
        }

        // Step 3: read digits
        long long num = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');

            // Step 4: overflow check
            if (num > INT_MAX) {
                return (sign == -1 ? INT_MIN : INT_MAX);
            }

            i++;
        }

        return sign * num;
    }
};
