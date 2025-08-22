class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty()) return 0;
        bool ispal = true;
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i]!=s[n-i-1]){
                ispal = false;
                break;
            }
        }
        return ispal ? 1:2;
    }
};