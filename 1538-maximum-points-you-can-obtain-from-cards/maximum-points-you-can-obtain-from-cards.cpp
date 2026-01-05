class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int totalSum = 0;
        // total sum using simple loop
        for(int i = 0; i < n; i++) {
            totalSum += cardPoints[i];
        }

        // if all cards are taken
        if(k == n) return totalSum;

        int windowSize = n - k;
        int windowSum = 0;

        // first window sum
        for(int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minSum = windowSum;

        // sliding the window
        for(int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i];                  // add right
            windowSum -= cardPoints[i - windowSize];     // remove left
            if(windowSum < minSum) {
                minSum = windowSum;
            }
        }

        return totalSum - minSum;
    }
};
