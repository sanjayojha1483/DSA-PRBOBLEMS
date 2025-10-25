class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n =nums.size();
        vector<int>ans(n);
        int l = 0, r = n-1;
        int pos = n-1;

        while(l<=r){
            int leftsquare = nums[l]*nums[l];
            int rightsquare = nums[r]*nums[r];

            if(leftsquare>rightsquare){
                ans[pos] = leftsquare;
                l++;
            }
            else{
                ans[pos] = rightsquare;
                r--;
            }
            pos--;
        }
        return ans;

    }
};