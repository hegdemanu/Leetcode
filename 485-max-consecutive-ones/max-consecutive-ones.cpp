class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcnt = -1;
        int cnt = 0;
      for(int n : nums){
        if (n == 1){
            cnt ++;
        }
        else{
            maxcnt = max(cnt, maxcnt);
            cnt = 0;
        }
      }
      return max(maxcnt, cnt);
    }
};