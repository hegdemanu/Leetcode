class Solution {
public:
    int majorityElement(vector<int>& arr) {
        if (arr.size() < 2) return arr[0];
        int slow = 0, fast = 1, count = 0;
        while(fast < arr.size()){
            if(arr[fast] == arr[slow]){
                count ++;
            }else{
                if(count > 0){
                    count --;
                }else {
                    count = 0;
                    slow = fast;
                }
            }
            fast++;
        }
return arr[slow];
    }
};