class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long k = n*n;
        long long sum = 0;
        long long sumo = k*(k+1)/2;
        long long sum2 = (k*(k+1)*(2*k+1))/6;
        long long sum1 = 0;
        // if (n ==1){
        //     return -1;
        // }
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                sum += grid[i][j];
                sum1 += grid[i][j]*grid[i][j];
            }
                
        }
            int x = sum - sumo;
            long long c = sum1 - sum2;
            int y = c/x;
            vector<int> a = {(x+y)/2, (y-x)/2};

        return a;
    }
};