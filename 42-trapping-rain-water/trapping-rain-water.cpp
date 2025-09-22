class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int water = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft)
                    maxLeft = height[left];  // update maxLeft
                else
                    water += maxLeft - height[left]; // trapped water
                left++;
            } else {
                if (height[right] >= maxRight)
                    maxRight = height[right]; // update maxRight
                else
                    water += maxRight - height[right]; // trapped water
                right--;
            }
        }

        return water;
    }
};
