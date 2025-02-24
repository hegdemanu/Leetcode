class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size() - 1;
        int m = arr[n];
        if (m == n + 1) return m + k;
        if (k >= m - n) return (m + k - (m - n ) + 1);
        int l = 0;
        int r = n;
        int cnt = 0;
        int mid = (l  + r) / 2;
        while(l <= r){
            
            // if (arr[mid] == (mid + 1)) l = mid + 1;// sortrd
            // else{
                if(l + 1 + cnt == arr[l]) l++;
                else{
                //   int ans = arr[l] - l + 1 - cnt;
                  cnt ++;// count = 1, kth is 1st,
                  if (k - cnt == 0) return (l + cnt);
                  cout << cnt;
                }
            // }
            
        }
      return -1;
    }
};