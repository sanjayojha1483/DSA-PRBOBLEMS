class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size()-1;
        int l =0;
        while(l<n){
            swap(s[l],s[n]);
            l++;
            n--;
        }
    }
};