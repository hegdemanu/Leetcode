class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        
        // 1. Safety: k can be larger than the array size
        k = k % n; 
        
        // 2. Reverse All
        // Input: [1, 2, 3, 4, 5, 6, 7], k=3
        // Result: [7, 6, 5, 4, 3, 2, 1]
        reverse(arr.begin(), arr.end());
        
        // 3. Reverse First 'k' elements
        // Result: [5, 6, 7, 4, 3, 2, 1]
        reverse(arr.begin(), arr.begin() + k);
        
        // 4. Reverse the Rest
        // Result: [5, 6, 7, 1, 2, 3, 4] -> SOLVED
        reverse(arr.begin() + k, arr.end());
    }
};