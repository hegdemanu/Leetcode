class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int sum = 0, maxi = a[0];  // Initialize maxi to first element instead of INT_MIN

        for (int i = 0; i < a.size(); i++) {
            sum += a[i];

            if (sum > maxi) {  // Avoid using max() function
                maxi = sum;
            }

            if (sum < 0) {  // Reset the sum to zero if it's negative
                sum = 0;
            }
        }
        return maxi;
    }
};
