class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long currsum =0;
        for(int i=0; i<k; i++){
            currsum+=nums[i];
        }
        long long maxsum=currsum;
        for(int i=k; i<nums.size(); i++)
        {
            currsum+=nums[i];
            currsum-=nums[i-k];
            maxsum = max(maxsum,currsum);
        }
        return (double)maxsum/k;
    }
};