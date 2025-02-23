class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int h = nums.size() - 1;
        int l = 1;
        if (h == 0) return 0;
        if (nums[h] > nums[h - 1]) return h;
        if (nums[0] > nums[1]) return 0;
        
        while(h >= l){
            int mid = l + (h - l) / 2; 
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) return mid;
            if (nums[mid] >= nums[mid + 1])
                {
                 h = mid;
                }
                else{// if (nums[mid] >= nums[mid - 1]) 
                    l = mid;
                }
        }
        return -1;
    }
};