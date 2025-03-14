class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int r = arr.size() - 1;
        int m = arr[r];
        if (m == r + 1) return m + k;
        if (k >= m - r) return (m + k - (m - r ) + 1);
        int l = 0;
        while(l <= r){
            int mid = (l  + r) / 2;
            if ((arr[mid] - (mid + 1)) < k) l = mid + 1;
            else r = mid - 1;
            }
        
      return (l + k);
    }
};