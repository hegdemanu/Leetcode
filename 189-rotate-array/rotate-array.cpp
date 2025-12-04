class Solution {
public:
   // Helper function to reverse a portion of array
void reverse_range(vector<int>& arr, int left, int right) {
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void rotate(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;  // Handle k > n
    
    // Step 1: Reverse entire array [0, n-1]
    reverse_range(arr, 0, n - 1);
    
    // Step 2: Reverse first k elements [0, k-1]
    reverse_range(arr, 0, k - 1);
    
    // Step 3: Reverse remaining elements [k, n-1]
    reverse_range(arr, k, n - 1);
}
};