class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size() - 1;
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] > nums[mid + 1])
                high = mid;        // peak left me hai
            else
                low = mid + 1;     // peak right me hai
        }
        
        return low;   // peak index
    }
};
