class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int size = arr.size();
        if (size < 2) return arr[0];
        int slow = 0, fast = 1, count = 0;
        while(fast < size){
            if(arr[fast] == arr[slow]){
                count ++;
            }else if(count > 0){
                    count --;
                }else {
                    count = 0;
                    slow = fast;
                }
            fast++;
        }
return arr[slow];
    }
};