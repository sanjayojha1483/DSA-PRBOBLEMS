class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        // Step 1: count zeros
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0)
                zeros++;
        }

        int i = n - 1;
        int j = n + zeros - 1;

        // Step 2: move from right to left
        while (i < j) {
            if (j < n)
                arr[j] = arr[i];

            if (arr[i] == 0) {
                j--;
                if (j < n)
                    arr[j] = 0;
            }

            i--;
            j--;
        }
    }
};
