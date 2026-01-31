class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int left = 0, right = n - 1;
        char ans = letters[0];   // default wrap-around answer

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(letters[mid] > target) {
                ans = letters[mid];   // possible answer
                right = mid - 1;      // left side check karo
            } else {
                left = mid + 1;       // right side jao
            }
        }
        return ans;
    }
};
