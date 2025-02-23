class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = piles.size();
        int l = 1;
        int maxi = INT_MIN;
        long long x = 0;
        int mid = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        int high = maxi;
        // if max banana is eaten it can be completed in min time
        if (h == n)
            return maxi;
        if (h < n)
            return -1;
        while (high >= l) {
            x = 0;
            mid = (high - l) / 2 + l;
            for (int i = 0; i < n; i++) {
                x += ((piles[i] + mid - 1) /
                      mid); // i am getting garbage x values
                if (x > h)
                    break;
            }
            if (x > h) {
                l = mid + 1;
            } else if (x <= h)
                high = mid - 1;
        }
        return l;
    }
};