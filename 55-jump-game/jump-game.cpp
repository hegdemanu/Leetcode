class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int lastIndex = nums.size() - 1;

        for (int i = 0; i <= maxReach; i++) { // Only iterate up to where we can reach
            
            // Update maxReach based on current position + jump power
            maxReach = max(maxReach, i + nums[i]);
            
            // If we can reach the end, we are done
            if (maxReach >= lastIndex) {
                return true;
            }
        }
        
        // If we finished the loop and couldn't reach the end
        return false;
    }
};