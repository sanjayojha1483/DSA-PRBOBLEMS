class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //phase 1 isme meeting point dekhenge 
        int slow= nums[0];
        int fast= nums[0];
        do{
            slow= nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        //phase 2 now duplicate no. searching
        int ptr1 = nums[0];
        int ptr2 = slow;
        while(ptr1!=ptr2){
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }
};