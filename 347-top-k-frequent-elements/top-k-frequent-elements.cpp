class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Count frequency
        unordered_map<int,int> freq;
        for (int i = 0; i < n; ++i) {
            freq[nums[i]]++;
        }

        // Step 2: Buckets (index = frequency)
        vector<vector<int>> buckets(n + 1);
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int num = it->first;
            int f = it->second;
            buckets[f].push_back(num);
        }

        // Step 3: Collect top K frequent elements
        vector<int> res;
        for (int f = n; f >= 1 && res.size() < k; --f) {
            for (int j = 0; j < buckets[f].size() && res.size() < k; ++j) {
                res.push_back(buckets[f][j]);
            }
        }

        // Step 4: Return result
        return res;
    }
};
