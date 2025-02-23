class Solution {
    bool helper (vector<int>& weights, int days, int mid){
        int sum = 0;
        // int day = 1;
        days--;
       for( int w : weights){
        sum += w;
          if(sum > mid){
            days --;
            if(days < 0) break;
            sum = w;// set to current weight
          }
       }
       if (days >= 0) return 1;
       else return 0;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int min = *max_element(weights.begin(), weights.end());
       int max = accumulate(weights.begin(), weights.end(), 0ll);
        while(max > min){
            int mid = min + (max - min) / 2;
            if(helper(weights, days, mid)){
                max = mid ;
            }
            else min = mid + 1;

        }
        return min;
    }
};