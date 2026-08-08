class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, profit = 0, maxprofit = 0;
        int n = prices.size();
        for(int sell = 1; sell < n; sell++){
            if(prices[buy] < prices[sell]){
                profit = prices[sell] - prices[buy];
                maxprofit = max(maxprofit, profit);
            } else{
                buy = sell;
            }
        }
        return maxprofit;
    }
};