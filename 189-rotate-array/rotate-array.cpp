class Solution {
public:
    void reverse(vector<int>& nums, int l,int r){
        while(l<r){
            swap(nums[l],nums[r]);
                l++;
                r--;
            
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        //reverse whole array 1234567 -> 7654321
        reverse(nums,0,n-1);
        //reverse k elements  7654321->5674321
        reverse(nums,0,k-1);
        //reverse remaining 5674321 -> 5671234
        reverse(nums,k,n-1);
        
    }
};