int getSum(vector<int>& arr, int n) {
        int sum = 0;
        for (int i : arr) {
                sum += i / n;
                if (i % n) sum++;
            
    }
        return sum;
}

class Solution {
public:
    int smallestDivisor(vector<int>& arr, int threshold) {
        int maxi = *max_element(arr.begin(), arr.end());
        int ans = maxi;
        int low = 1, high = maxi;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int th = getSum(arr, mid);
            if (th > threshold) {
                low = mid + 1;
            } else {
                ans = min(ans, mid);
                high = mid - 1;        
            }
        }
        return ans;
    }
};