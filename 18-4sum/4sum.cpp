class Solution {
    // 
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> sol;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < n - 1; j++) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue;
            int k = j + 1;
            int l = n - 1;
                while(k < l) {
                    long long sum =(long long) nums[i] + nums[j] + nums[k] + nums[l];
                    if ( sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sol.push_back(temp);
                        while ( k < l && nums[k] == nums[k + 1]) k++;
                        while (k < l && nums[l] == nums[l-1]) l--;
                        k++, l--;

                    } else if (sum > target) {
                        l--;
                    } else if (sum< target) {
                        k++;
                    }
                }
            }
        }
        return sol;
    }
};