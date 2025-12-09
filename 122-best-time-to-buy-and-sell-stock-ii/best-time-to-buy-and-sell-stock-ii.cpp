class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        // Start from the second element (index 1)
        for (int i = 1; i < prices.size(); i++) {
            // If price went up compared to yesterday, we take that profit
            if (prices[i] > prices[i-1]) {
                profit += prices[i] - prices[i-1];
            }
        }
        
        return profit;
    }
};