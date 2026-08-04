class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int buy_prices = prices[0];
        int max_profit = 0;

        for(int i=1; i<n; i++){
            if(buy_prices > prices[i]){
                buy_prices = prices[i];
            }

            else{
                max_profit = max(max_profit, prices[i] - buy_prices);
            }
        }

        return max_profit;
    }
};