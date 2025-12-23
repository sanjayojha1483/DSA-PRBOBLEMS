class Solution {
public:
    string buildString(string s) {
        string result = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#') {
                result.push_back(s[i]);   // normal character
            } else if (!result.empty()) {
                result.pop_back();        // backspace
            }
        }
        return result;
    }

    bool backspaceCompare(string s, string t) {
        return buildString(s) == buildString(t);
    }
};
