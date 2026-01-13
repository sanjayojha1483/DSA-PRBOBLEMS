class Solution {
public:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int slow = i;
            int fast = i;

            bool dir = nums[i] > 0;   // direction

            while (true) {
                slow = nextIndex(nums, slow);

                // fast moves 2 steps
                fast = nextIndex(nums, fast);
                if ((nums[fast] > 0) != dir) break;
                fast = nextIndex(nums, fast);

                // direction change
                if ((nums[slow] > 0) != dir || (nums[fast] > 0) != dir)
                    break;

                // self loop
                if (slow == nextIndex(nums, slow))
                    break;

                if (slow == fast)
                    return true;
            }
        }
        return false;
    }
};
