class Solution {
public:
    string sortSentence(string s) {
        vector<string> arr(10);  // max 9 words

        string word = "";
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == ' ') {
                int pos = word[word.size() - 1] - '0'; // last character number
                word.pop_back(); // remove the number
                arr[pos] = word;

                word = "";
            } 
            else {
                word += s[i];
            }
        }

        // last word handle karo
        int pos = word[word.size() - 1] - '0';
        word.pop_back();
        arr[pos] = word;

        // final answer build
        string ans = "";
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == "") continue;
            ans += arr[i] + " ";
        }

        ans.pop_back(); // last space hata do
        return ans;
    }
};
