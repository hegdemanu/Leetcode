class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    int max_freq = 0;
    int left = 0;
    for (int right = 0; right < n; ++right) {
        long long current_sum = prefix[right + 1] - prefix[left];
        long long target = (long long)nums[right] * (right - left + 1);
        long long required = target - current_sum;
        while (required > k) {
            left++;
            current_sum = prefix[right + 1] - prefix[left];
            target = (long long)nums[right] * (right - left + 1);
            required = target - current_sum;
        }
        max_freq = max(max_freq, right - left + 1);
    }
    return max_freq;
}
};