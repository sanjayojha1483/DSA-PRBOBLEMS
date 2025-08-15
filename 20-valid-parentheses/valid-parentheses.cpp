class Solution {
public:
// sanjay
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            char c = s[i];
            
            // Opening brackets
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // Closing brackets
            else {
                if(st.empty()) return false;
                char top = st.top();
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        
        return st.empty();
    }
};
