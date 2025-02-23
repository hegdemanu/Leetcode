class Solution {
public:
    bool bloomCheck(vector<int>& bloomDay, int k, int m, int day) {

        int cnt = 0, bouquets = 0;
        for (int bloom : bloomDay) {
            if (bloom <= day) {
                cnt++;
                if (cnt == k) { // No division, faster
                    bouquets++;
                    cnt = 0; // Reset count only when a bouquet is made
                    if (bouquets == m) return true;
                }
            } else {
                cnt = 0; // Reset when a flower isn't blooming
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1; // Impossible case

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (bloomCheck(bloomDay, k, m, mid)) {
                high = mid;  // Try a lower day
            } else {
                low = mid + 1; // Increase day
            }
        }
        return low;
    }
};
