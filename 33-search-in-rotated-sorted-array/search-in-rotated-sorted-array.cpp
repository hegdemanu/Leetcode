class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size() - 1;
        int low = 0;
        while (high >= low) {
            int mid = low + (high - low) / 2;
            if (target == nums[mid]) return mid;
            if (nums[mid] <= nums[high]) {
                if (target >= nums[mid] && target <= nums[high]) low = mid + 1;//sorted right && -->target
                else high = mid - 1;
            }
            else {
                if (target <= nums[mid] && target >= nums[0]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return -1;
    }
};