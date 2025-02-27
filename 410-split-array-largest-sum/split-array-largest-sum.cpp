class Solution {
    bool canSplit(vector<int>& nums, int k, int mid, int n){
        int sum = 0; int cnt = 1;
        for (int i = 0; i < n; i++){
            if((nums[i] + sum) <= mid){
                sum += nums[i];
            }
            else {
                sum = nums[i];
                cnt++;
                if (cnt > k) return false;
            }
        } 
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int r = accumulate(nums.begin(), nums.end(), 0);
        if (k == 1) return r;
        int l = *max_element(nums.begin(), nums.end());
        while(l < r){
            int mid = l + (r - l) / 2;
            if(canSplit(nums, k, mid, n)) {
                r = mid;
            }
            else l = mid + 1;
        }
        return r;
    }
};