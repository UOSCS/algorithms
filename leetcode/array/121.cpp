class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int current_price = prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > current_price)
                max_profit = max(max_profit, prices[i] - current_price);
            else
                current_price = prices[i];
        }
        
        return max_profit;
    }
};
