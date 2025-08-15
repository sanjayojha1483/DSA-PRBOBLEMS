class Solution {
public:
//sanjay
    int titleToNumber(string columnTitle) {
        long result = 0;
        for(int i = 0 ; i<columnTitle.size(); i++){
            int value = columnTitle[i] - 'A'+1;
            result = result*26 + value;
        }
        return result;
    }
};