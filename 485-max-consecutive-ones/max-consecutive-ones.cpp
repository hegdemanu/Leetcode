class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcnt=0;
        int count=0;
        for(int n : nums){
            if(n==1){
                count++;
                if(count>maxcnt){
                    maxcnt=count;
                }
            }
            else{
                count=0;
            }
        }
        return maxcnt;
    }
};