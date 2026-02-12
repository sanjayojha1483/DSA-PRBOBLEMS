class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;

        int officer = 0; // ye first se chalega 

        for(int cm = 1; cm < nums.size(); cm++) { //cm har index pr jayega
            if(nums[cm] != nums[officer]) {
                officer++;
                nums[officer] = nums[cm];
            }
        }

        return officer + 1;
    }
};
