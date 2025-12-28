class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        for (int i = 1; i < n - 1; i++) {

            // check peak
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {

                int l = i;
                int r = i;

                // left side (increasing)
                while (l > 0 && arr[l] > arr[l - 1]) {
                    l--;
                }

                // right side (decreasing)
                while (r < n - 1 && arr[r] > arr[r + 1]) {
                    r++;
                }

                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
