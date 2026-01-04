class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int target = threshold * k;
        int windowSum = 0;
        int count = 0;

        // First window sum
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        if (windowSum >= target) {
            count++;
        }

        // Sliding the window
        for (int i = k; i < n; i++) {
            windowSum += arr[i];
            windowSum -= arr[i - k];

            if (windowSum >= target) {
                count++;
            }
        }

        return count;
    }
};
