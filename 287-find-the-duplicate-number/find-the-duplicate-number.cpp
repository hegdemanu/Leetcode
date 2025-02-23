class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    if (nums[0] == nums[1]){
            return nums[0];
    }
     int i = 0;
     int n = nums.size();
     vector<int> a(n,0);
     while(i < n){
     a[nums[i]]++;
     if ( a[nums[i]] == 2){
     return nums[i];
     break;}
        i++;
     }
     return -1;
    }
};