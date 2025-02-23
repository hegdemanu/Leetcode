class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int h = nums.size() - 1;
       int l = 0;
       int ans = 0;
       while(l <= h){
        int mid = l + (h - l) / 2;
        if ( target == nums[mid]) return mid;
        else if ( target < nums[mid]){
          h = mid - 1;
        }
         else if ( target > nums[mid]){
          l = mid + 1;
        }
       }
       
       return l;
    }
};