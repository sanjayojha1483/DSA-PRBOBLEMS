class Solution {
public:
    bool isPalindrome(int x) {
    if(x<0 || (x%10==0 && x!=0 )){
        return false ;
    }
    int reversed = 0;
    while(x>reversed){
        int lastdigit = x%10;
        reversed = reversed *10 + lastdigit;
        x = x/10;
    }
    return (x==reversed || x ==reversed /10);
    }
};