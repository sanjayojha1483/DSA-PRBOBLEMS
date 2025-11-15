class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       vector<int>freq(26,0);

       for(int i=0; i<magazine.size(); i++){
        char c = magazine[i];
        freq[c-'a']++;

       } 
       for(int i=0; i<ransomNote.size(); i++){
        char c = ransomNote[i];
        if(freq[c-'a']==0)
        return false;
        freq[c-'a']--;
       }
       return true;
    }
};