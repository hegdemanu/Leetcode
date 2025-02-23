class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        ranges :: sort(nums);
        int largest = 1;
        int cnt = 1;
        for (int i = 0; i < size - 1; i++) {
            if (nums[i] + 1 == nums[i + 1] ){
                cnt++;
            }
            else if (nums[i] == nums[i + 1]) continue;
            else {
                cnt = 1;
            }
            largest = max(largest, cnt);
            
        }
        return largest;
    }
};