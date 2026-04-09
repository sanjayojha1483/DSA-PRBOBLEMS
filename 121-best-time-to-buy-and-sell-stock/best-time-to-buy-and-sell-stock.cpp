class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<minprice){
                minprice = prices[i];

            }
            else{
                int profit = prices[i]-minprice ;
                if(profit>maxprofit){
                    maxprofit = profit;
                }

            }
        }
        return maxprofit;
        
    }
};