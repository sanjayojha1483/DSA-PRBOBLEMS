class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string curr = "";
        int num = 0;

        for (int i = 0; i < s.size(); i++) {

            // Step 1: Build number
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            // Step 2: If '[' comes -> push current things
            else if (s[i] == '[') {
                numStack.push(num);
                strStack.push(curr);
                num = 0;
                curr = "";
            }

            // Step 3: When ']' comes -> repeat string
            else if (s[i] == ']') {
                int repeat = numStack.top(); numStack.pop();
                string prev = strStack.top(); strStack.pop();

                string temp = "";
                for (int j = 0; j < repeat; j++)
                    temp += curr;

                curr = prev + temp;
            }

            // Step 4: Normal letters
            else {
                curr += s[i];
            }
        }

        return curr;
    }
};
