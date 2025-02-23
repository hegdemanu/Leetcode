class Solution {
public:
    int bs(vector<int>& nums, int l, int h, int target) {
        if (l > h) return -1;
        int mid = l + (h - l) / 2;
        if (target < nums[mid]) return bs(nums, l, mid - 1, target);
        else if (target > nums[mid]) return bs(nums, mid + 1, h, target);
        else return mid;
    }
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        if (h + 1 < 2) {
            if (nums[0] == target) {
                return 0;
            } else {
                return -1;
            }
        }
        int result = bs(nums, l, h, target);
        return result;
    }
};