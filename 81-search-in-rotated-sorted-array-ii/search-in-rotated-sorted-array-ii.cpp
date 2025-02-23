class Solution {
    bool tsearch(vector<int>& nums, int target){

        int high = nums.size() - 1;
        int low = 0;
        while (high >= low) {
            int mid = low + (high - low) / 2;
            if (target == nums[mid]) return true;
            if(nums[mid] == nums[high] && nums[mid] == nums[low]){
                low++; high--;
                continue;
            }
            if (nums[mid] <= nums[high]) {
                if (target >= nums[mid] && target <= nums[high]) low = mid + 1;//sorted right && -->target
                else high = mid - 1;
            }
            else {
                if (target <= nums[mid] && target >= nums[0]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        return (tsearch(nums, target));
    }
};