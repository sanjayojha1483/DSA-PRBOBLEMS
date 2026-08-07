class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> ans;

        int expected = 1;

        for (int i = 0; i < n; i++) {

            if (nums[i] == expected) {
                expected++;
            }
            else if (nums[i] > expected) {
                ans.push_back(expected);
                expected++;
                i--;   // check same nums[i] again
            }
        }

        while (expected <= n) {
            ans.push_back(expected);
            expected++;
        }

        return ans;
    }
};