#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1; // Map value to index
            
            // If the value at the index is negative, it means we've seen this number before
            if (nums[index] < 0) {
                duplicates.push_back(abs(nums[i]));
            } else {
                nums[index] = -nums[index]; // Mark the number as visited
            }
        }
        
        return duplicates;
    }
};
