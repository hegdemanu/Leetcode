class Solution {
    int pivot(vector<int>& nums, int high, int low){
        while(high > low){
            int mid = low + (high-low)/2 ;
            if (nums[mid] == nums[high] && nums[mid] == nums[low]){
                low ++; high--;
                continue;
            }
            else if (nums[mid] > nums[high] ) low = mid +1;
            else high = mid;
        }
        return nums[low];
        }
    
public:
    int findMin(vector<int>& nums) {
        return pivot(nums, nums.size() - 1, 0);
    };
};