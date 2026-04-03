class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();

        vector<int> freq(26,0);

        int maxLen = 0;
        int maxFreq = 0;
        int windowSize = 0;

        int j=0;

        for(int i=0; i<n; i++){
            freq[s[i] - 'A']++;
            maxFreq = max(maxFreq, freq[s[i] - 'A']);

            windowSize = i-j+1;

            if(windowSize - maxFreq > k){
                freq[s[j] - 'A']--;
                j++;
            }

            maxLen = max(maxLen, i-j+1);

        }
        
        return maxLen;
    }
};