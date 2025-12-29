class Solution {
public:
    bool isSubsequence(string s, string w) {
        int i = 0, j = 0;

        while (i < s.size() && j < w.size()) {
            if (s[i] == w[j]) {
                j++;   // word ka char match hua
            }
            i++;       // s hamesha aage badhta rahega
        }

        return j == w.size(); // agar word poora match ho gaya
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";

        for (int i = 0; i < dictionary.size(); i++) {
            string w = dictionary[i];

            if (isSubsequence(s, w)) {
                if (w.size() > ans.size() ||
                   (w.size() == ans.size() && w < ans)) {
                    ans = w;
                }
            }
        }

        return ans;
    }
};
