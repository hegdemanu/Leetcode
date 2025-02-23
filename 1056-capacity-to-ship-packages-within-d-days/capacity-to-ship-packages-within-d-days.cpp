class Solution {
    bool helper (vector<int>& weights, int days, int mid){
        int sum = 0;
        int day = 1;
       for( int w : weights){
        sum += w;
          if(sum > mid){
            day ++;
            sum = w;// set to current weight
          }
       }
       if (days >= day) return 1;
       else return 0;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int min = *max_element(weights.begin(), weights.end());
       int max = accumulate(weights.begin(), weights.end(), 0ll);
        while(max >= min){
            int mid = min + (max - min) / 2;
            if(helper(weights, days, mid)){
                max = mid - 1;
            }
            else min = mid + 1;

        }
        return min;
    }
};