class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, n;
        int buy, sell;
        int max_profit;
        
        i = 0;
        n = prices.size();
        max_profit = 0;
        while (i < n - 1) {
            // Contiguous descending block
            while (i < n - 1 && prices[i] >= prices[i + 1]) {
                ++i;
            }
            buy = prices[i];
            
            // Contiguous ascending block
            while (i < n - 1 && prices[i] < prices[i + 1]) {
                ++i;
            }
            sell = prices[i];
            
            max_profit += sell - buy;
        }
        
        return max_profit;
    }
};