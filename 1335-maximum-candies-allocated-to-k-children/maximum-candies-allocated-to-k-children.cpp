class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long total = accumulate(candies.begin(), candies.end(),0ll);
        if(total < k) return 0;
        int l = 1, r = *max_element(candies.begin(), candies.end());
        while (l <= r){
            int mid = (l + (r-l)/2);
            long long distro = 0;
            for(int s : candies){
                distro += s/mid;
            }
            if(distro >= k){
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return r;
    }
};