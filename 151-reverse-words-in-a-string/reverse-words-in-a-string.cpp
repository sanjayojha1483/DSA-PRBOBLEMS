class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> words;
        int i = 0;
        int n = s.length();
        
        while(i < n) {
            
            // Skip spaces
            while(i < n && s[i] == ' ')
                i++;
            
            string word = "";
            
            // Extract word
            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            
            if(word.length() > 0)
                words.push_back(word);
        }
        
        // Reverse words
        reverse(words.begin(), words.end());
        
        // Join words with single space
        string result = "";
        for(int i = 0; i < words.size(); i++) {
            result += words[i];
            if(i != words.size() - 1)
                result += " ";
        }
        
        return result;
    }
};