class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Handle case where k > n
        
        if (k == 0) return;  // No rotation needed
        
        // 1. Reverse entire array
        reverse(nums.begin(), nums.end());
        
        // 2. Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // 3. Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};