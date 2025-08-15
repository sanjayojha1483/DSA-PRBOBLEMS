class Solution {
public:
//sanjay
    bool detectCapitalUse(string word) {
        if(word.length() == 0) return true;
        int cnt = 0;
        int len = word.length();
        for(int i=0; i<len; i++){
            int ch = word[i];
            if(ch>=65 && ch<91){
                cnt++;
            }

        }
        if(cnt == len) return true;
        if(cnt == 0) return true;
        if(cnt == 1 && word[0]>=65 && word[0]<91 )
        return  true; 
        return false;
    }
};