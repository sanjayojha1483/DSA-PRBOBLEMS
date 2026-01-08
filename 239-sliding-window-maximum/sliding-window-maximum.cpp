class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;   // stores INDEXES, not values
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            // Step 1: remove smaller elements from back
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Step 2: push current index
            dq.push_back(i);

            // Step 3: remove elements outside window
            if(dq.front() <= i - k) {
                dq.pop_front();
            }

            // Step 4: store result when window starts
            if(i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
