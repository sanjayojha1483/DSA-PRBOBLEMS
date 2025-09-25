class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        int number = 0;
        int sign = 1;  // +1 for positive, -1 for negative

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                number = number * 10 + (c - '0'); // build number
            } 
            else if (c == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } 
            else if (c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } 
            else if (c == '(') {
                st.push(result);  // save previous result
                st.push(sign);    // save previous sign
                result = 0;
                sign = 1;
            } 
            else if (c == ')') {
                result += sign * number; 
                number = 0;
                result *= st.top(); st.pop(); // apply sign before '('
                result += st.top(); st.pop(); // add previous result
            }
        }

        result += sign * number;  // add last number
        return result;
    }
};
