class Solution {
    int climber ( vector<int> &memo, int n){
        if (n<2) return 1;
        else if (n == 2) return 2;
        if (memo[n] != 0) return memo[n];
        else {
           return memo[n] += climber(memo, n -1) + climber(memo, n-2);
        }
    }
public:
    int climbStairs(int n) {
        int ways = 0;
        vector<int> memo(n+1, 0);
        return climber(memo, n);
    }
};