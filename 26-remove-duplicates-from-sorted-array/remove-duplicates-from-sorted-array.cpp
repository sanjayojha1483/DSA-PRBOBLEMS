class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;

        int officer = 0;
        int res = 1;
        int cm = 1;

        while(cm < nums.size()) {

            if(nums[cm] == nums[cm - 1]) {
                cm++;
                continue;
            }

            nums[officer + 1] = nums[cm];
            officer++;
            res++;
            cm++;
        }

        return res;
    }
};
