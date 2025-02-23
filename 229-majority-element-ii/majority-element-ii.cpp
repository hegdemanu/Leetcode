class Solution {
public:
    // Extended Boyer Moore's Voting Algorithm
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        // this statements are just to beat space, otherwise not usefull
        //ok it doesnt matter leetcode is shitty anyway
        if (n < 2) {
            return nums;
        } else if (n < 3) {
            if (nums[0] == nums[1]) {
                ans.push_back(nums[0]);
                return ans;
            } else
                return nums;

        } else if (n < 4) {
            if (nums[0] == nums[1]) {
                ans.push_back(nums[0]);
                return ans;
            } else if (nums[2] == nums[1]) {
                ans.push_back(nums[1]);
                return ans;
            } else if (nums[2] == nums[0]) {
                ans.push_back(nums[0]);
                return ans;
            }
        }
        // only this part also will work fine, improvements of the codes are3
        // negligible
        else {
            int cnt1 = 0;
            int cnt2 = 0;
            int el1 = INT_MIN;
            int el2 = INT_MIN;
            for (int i = 0; i < n; i++) {
                if (cnt1 == 0 && el2 != nums[i]) {
                    el1 = nums[i];
                    cnt1 = 1;
                } else if (cnt2 == 0 && el1 != nums[i]) {
                    el2 = nums[i];
                    cnt2 = 1;
                } else if (el1 == nums[i])
                    cnt1++;
                else if (el2 == nums[i])
                    cnt2++;
                else {
                    cnt1--, cnt2--;
                }
            }

            cnt1 = 0;
            cnt2 = 0;

            for (int i = 0; i < n; i++) {
                if (nums[i] == el1)
                    cnt1++;
                else if (nums[i] == el2)
                    cnt2++;
            }

            if (cnt1 > n / 3)
                ans.push_back(el1);
            if (cnt2 > n / 3)
                ans.push_back(el2);

            return ans;
        }
        return ans;
    }
};