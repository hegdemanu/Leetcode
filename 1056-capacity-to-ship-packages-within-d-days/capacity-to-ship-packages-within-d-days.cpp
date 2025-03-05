class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int min = *max_element(weights.begin(), weights.end());
        int max = accumulate(weights.begin(), weights.end(), 0ll);

        while (max > min) {
            int mid = min + (max - min) / 2;
            int sum = 0, remainingDays = days - 1; // Use a separate counter to avoid modifying `days`
            
            for (int w : weights) {
                sum += w;
                if (sum > mid) {
                    remainingDays--;
                    if (remainingDays < 0) break;
                    sum = w;
                }
            }
            
            if (remainingDays >= 0) max = mid;
            else min = mid + 1;
        }
        return min;
    }
};
